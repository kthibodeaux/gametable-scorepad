#pragma once
#include <stdint.h>
#include "IDisplay.h"

class Game {
public:
  virtual ~Game() {}
  virtual const char* name() const = 0;
  virtual void onStart() = 0;
  // Returns true if the display needs to be redrawn as a result.
  virtual bool onButtonPress(uint8_t buttonIndex) = 0;
  virtual void render(IDisplay& display) = 0;
};
