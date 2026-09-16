# Gametable Scorepad

Firmware for the gametable's scorepads: battery-powered ESP32-C3 Super Mini
devices, each with a 16x2 I2C LCD and 8 buttons behind a PCF8575 IO
expander, used to keep score for tabletop games. Each scorepad runs
standalone — there's no communication between pads.

## Hardware

- ESP32-C3 Super Mini (built with `esp32:esp32:esp32c3:CDCOnBoot=cdc` --
  CDC-on-boot is required for Serial to show up over the board's native
  USB port)
- 16x2 I2C LCD (`LiquidCrystal_I2C`), address `0x27`
- PCF8575 16-channel I2C IO expander (`PCF8575` by Rob Tillaart), address
  `0x20`
- 8 buttons, wired active-low (expander's weak pull-ups) to the expander
  channels listed in `src/Pins.h`
- I2C bus (LCD + expander) on GPIO4 (SDA) / GPIO5 (SCL). GPIO8/GPIO9, the
  core's I2C defaults, are avoided: both are strapping pins, and GPIO8 also
  drives the onboard status LED.
- Adafruit MAX17048 LiPoly fuel gauge, address `0x36` (shares the same I2C
  bus; no extra GPIO needed unless the `ALRT` interrupt pin is wired up)

## Build and flash

```
arduino-cli compile --fqbn esp32:esp32:esp32c3:CDCOnBoot=cdc .
arduino-cli upload --fqbn esp32:esp32:esp32c3:CDCOnBoot=cdc -p /dev/ttyACM0 .
```

`sketch.yaml` pins the board FQBN, port, baud rate, and library versions used
by this sketch.

## Running the unit tests

Game logic (`Game`, `GameManager`, `CounterGame`, etc.) is plain C++ with no
Arduino dependency, so it's tested on the host machine instead of on device:

```
./test/run_tests.sh
```

`ButtonReader` and `Display` are the only two files that touch GPIO/I2C
directly; they're verified manually on real hardware instead.

## Scorepad identity (scorepadColor)

Each scorepad persists a single string, `scorepadColor`, in flash (via the
ESP32 `Preferences`/NVS storage) so it survives reboots and reflashes. On
first boot it defaults to `"unassigned"`.

To view or change it, hold down buttons 6 and 7 while powering on the
device. The LCD shows "Serial Mode"; over Serial (115200 baud) you get a
menu:

```
=== Scorepad Provisioning ===
1. Show color
2. Set color
Choice:
```

Choosing "2" prompts for a new value and saves it immediately. This mode
runs until the device is reset — there's no path back to normal boot from
here, matching the rest of the platform's power-cycle-to-exit model.

## Adding a new game

1. Create `src/games/YourGame.h` / `.cpp` implementing the `Game` interface:
   `name()`, `onStart()`, `onButtonPress()`, `render()`.
2. Add unit tests in `test/test_your_game.cpp` using `FakeDisplay` and
   `FakeEventSink`, and register them in `test/main.cpp` and
   `test/run_tests.sh`.
3. Register an instance in the `games[]` array in `gametable.ino`.

No changes to `GameManager`, `ButtonReader`, or `Display` are needed — that's
the point of the `Game` interface.
