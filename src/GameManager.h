#pragma once
#include <stdint.h>
#include "Game.h"

class GameManager {
public:
  GameManager(Game** games, uint8_t gameCount);

  // Returns true if the display needs to be redrawn as a result.
  bool handleButtonPress(uint8_t buttonIndex);
  void render(IDisplay& display);

private:
  enum class Mode { Menu, Playing };

  static constexpr uint8_t kNextButton = 0;
  static constexpr uint8_t kPrevButton = 1;
  static constexpr uint8_t kSelectButton = 2;

  Game** games_;
  uint8_t gameCount_;
  uint8_t selection_ = 0;
  Mode mode_ = Mode::Menu;
  Game* activeGame_ = nullptr;

  bool handleMenuButton(uint8_t buttonIndex);
  void renderMenu(IDisplay& display);
};
