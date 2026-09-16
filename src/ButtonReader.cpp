#include "ButtonReader.h"

void ButtonReader::begin() {
  expander_.begin();
}

bool ButtonReader::poll(uint8_t& pressedIndex) {
  unsigned long now = millis();
  uint16_t state = expander_.readButton16();
  for (uint8_t i = 0; i < kButtonCount; i++) {
    bool pressedNow = (state & (1u << kButtonPins[i])) == 0;
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

bool ButtonReader::isPressedNow(uint8_t buttonIndex) {
  return expander_.readButton(kButtonPins[buttonIndex]) == 0;
}
