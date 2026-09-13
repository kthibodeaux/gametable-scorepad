# Gametable Scorepad

Firmware for the gametable's scorepads: battery-powered ESP32-S3 devices,
each with a 16x2 I2C LCD and 8 direct-GPIO buttons, used to keep score for
tabletop games. Each scorepad runs standalone — there's no communication
between pads.

## Hardware

- ESP32-S3 (built with `esp32:esp32:esp32s3:PSRAM=opi`)
- 16x2 I2C LCD (`LiquidCrystal_I2C`)
- 8 buttons, wired active-low with internal pull-ups to the GPIO pins listed
  in `src/Pins.h`

## Build and flash

```
arduino-cli compile --fqbn esp32:esp32:esp32s3:PSRAM=opi .
arduino-cli upload --fqbn esp32:esp32:esp32s3:PSRAM=opi -p /dev/ttyACM0 .
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

## Adding a new game

1. Create `src/games/YourGame.h` / `.cpp` implementing the `Game` interface:
   `name()`, `onStart()`, `onButtonPress()`, `render()`.
2. Add unit tests in `test/test_your_game.cpp` using `FakeDisplay` and
   `FakeEventSink`, and register them in `test/main.cpp` and
   `test/run_tests.sh`.
3. Register an instance in the `games[]` array in `gametable.ino`.

No changes to `GameManager`, `ButtonReader`, or `Display` are needed — that's
the point of the `Game` interface.
