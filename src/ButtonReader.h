#pragma once
#include <stdint.h>
#include "Pins.h"

// Polls kButtonCount buttons wired active-low with internal pull-ups.
// Reports one newly-pressed button per call, debounced.
class ButtonReader {
public:
  void begin();
  // Returns true and sets pressedIndex if a new button press was detected.
  bool poll(uint8_t& pressedIndex);

private:
  bool lastRawPressed_[kButtonCount] = {};
  bool lastStablePressed_[kButtonCount] = {};
  unsigned long lastChangeMs_[kButtonCount] = {};
};
