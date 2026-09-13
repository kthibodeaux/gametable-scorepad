#pragma once
#include <stdint.h>

// Placeholder pin assignments -- update these to match the actual wiring
// once the scorepad's breadboard/PCB layout is finalized.
constexpr uint8_t kButtonCount = 8;
constexpr uint8_t kButtonPins[kButtonCount] = {0, 1, 15, 16, 4, 5, 6, 7};

constexpr uint8_t kLcdI2cAddress = 0x27;
constexpr uint8_t kLcdCols = 16;
constexpr uint8_t kLcdRows = 2;

constexpr unsigned long kDebounceMs = 50;

// Holding both of these buttons down at boot enters serial provisioning
// mode, letting scorepadColor be set over Serial.
constexpr uint8_t kSerialModeButtonIndexA = 0;
constexpr uint8_t kSerialModeButtonIndexB = 7;
