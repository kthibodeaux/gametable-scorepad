#pragma once
#include "../../src/IDisplay.h"
#include <string>

class FakeDisplay : public IDisplay {
public:
  std::string line0;
  std::string line1;

  void printLine(uint8_t row, const char* text) override {
    if (row == 0) {
      line0 = text;
    } else if (row == 1) {
      line1 = text;
    }
  }
};
