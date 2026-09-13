#include "ButtonReader.h"
#include <Arduino.h>

void ButtonReader::begin() {
  for (uint8_t i = 0; i < kButtonCount; i++) {
    pinMode(kButtonPins[i], INPUT_PULLUP);
  }
}

bool ButtonReader::poll(uint8_t& pressedIndex) {
  unsigned long now = millis();
  for (uint8_t i = 0; i < kButtonCount; i++) {
    bool pressedNow = digitalRead(kButtonPins[i]) == LOW;
    if (pressedNow != lastRawPressed_[i]) {
      lastRawPressed_[i] = pressedNow;
      lastChangeMs_[i] = now;
    } else if (pressedNow != lastStablePressed_[i] &&
               (now - lastChangeMs_[i]) >= kDebounceMs) {
      lastStablePressed_[i] = pressedNow;
      if (pressedNow) {
        pressedIndex = i;
        return true;
      }
    }
  }
  return false;
}
