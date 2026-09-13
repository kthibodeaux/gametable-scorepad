#pragma once
#include "IDisplay.h"
#include "Pins.h"
#include <LiquidCrystal_I2C.h>

class Display : public IDisplay {
public:
  void begin();
  void printLine(uint8_t row, const char* text) override;

private:
  LiquidCrystal_I2C lcd_{kLcdI2cAddress, kLcdCols, kLcdRows};
};
