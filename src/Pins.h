#pragma once
#include <stdint.h>

// ESP32-C3 Super Mini I2C bus. GPIO8/GPIO9 (the core's I2C defaults) are
// avoided: both are strapping pins, and GPIO8 also drives the onboard
// status LED, so they're unreliable for a shared bus.
constexpr uint8_t kSdaPin = 4;
constexpr uint8_t kSclPin = 5;

// Buttons are wired to a PCF8575 16-channel I2C IO expander instead of
// direct GPIOs, active-low (expander's weak pull-ups act like INPUT_PULLUP).
// Channel assignments match the scorepad's actual breadboard wiring.
constexpr uint8_t kPcf8575I2cAddress = 0x20;
constexpr uint8_t kButtonCount = 8;
constexpr uint8_t kButtonPins[kButtonCount] = {8, 9, 10, 11, 7, 6, 5, 4};

constexpr uint8_t kLcdI2cAddress = 0x27;
constexpr uint8_t kLcdCols = 16;
constexpr uint8_t kLcdRows = 2;

constexpr unsigned long kDebounceMs = 50;

// Holding both of these buttons down at boot enters serial provisioning
// mode, letting scorepadColor be set over Serial.
constexpr uint8_t kSerialModeButtonIndexA = 6;
constexpr uint8_t kSerialModeButtonIndexB = 7;
