#include "Display.h"
#include <cstring>

// Wire.begin() is called once, centrally, in gametable.ino's setup() --
// the LCD and the PCF8575 button expander share one I2C bus.
void Display::begin() {
  lcd_.init();
  lcd_.backlight();
}

void Display::printLine(uint8_t row, const char* text) {
  char padded[kLcdCols + 1];
  std::memset(padded, ' ', kLcdCols);
  padded[kLcdCols] = '\0';
  size_t len = std::strlen(text);
  if (len > kLcdCols) len = kLcdCols;
  std::memcpy(padded, text, len);
  lcd_.setCursor(0, row);
  lcd_.print(padded);
}
