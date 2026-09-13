#pragma once
#include <stdint.h>

class IDisplay {
public:
  virtual ~IDisplay() {}
  // Writes text to the given row (0 or 1), padding or truncating to 16
  // columns so leftover characters from a previous, longer string never
  // linger on the LCD.
  virtual void printLine(uint8_t row, const char* text) = 0;
};
