#pragma once
#include <stdint.h>
#include <PCF8575.h>
#include "Pins.h"

// Polls kButtonCount buttons wired active-low (via a PCF8575 IO expander's
// weak pull-ups). Reports one newly-pressed button per call, debounced.
class ButtonReader {
public:
  void begin();
  // Returns true and sets pressedIndex if a new button press was detected.
  bool poll(uint8_t& pressedIndex);
  // Raw, undebounced read of a single button's current state. Used at boot
  // to check the serial-provisioning combo before polling starts.
  bool isPressedNow(uint8_t buttonIndex);

private:
  PCF8575 expander_{kPcf8575I2cAddress};
  bool lastRawPressed_[kButtonCount] = {};
  bool lastStablePressed_[kButtonCount] = {};
  unsigned long lastChangeMs_[kButtonCount] = {};
};
