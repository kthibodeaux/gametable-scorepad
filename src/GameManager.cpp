#include "GameManager.h"

GameManager::GameManager(Game** games, uint8_t gameCount)
    : games_(games), gameCount_(gameCount) {}

bool GameManager::handleButtonPress(uint8_t buttonIndex) {
  if (mode_ == Mode::Menu) {
    return handleMenuButton(buttonIndex);
  }
  return activeGame_->onButtonPress(buttonIndex);
}

bool GameManager::handleMenuButton(uint8_t buttonIndex) {
  if (buttonIndex == kNextButton) {
    selection_ = (selection_ + 1) % gameCount_;
    return true;
  }
  if (buttonIndex == kPrevButton) {
    selection_ = (selection_ + gameCount_ - 1) % gameCount_;
    return true;
  }
  if (buttonIndex == kSelectButton) {
    activeGame_ = games_[selection_];
    activeGame_->onStart();
    mode_ = Mode::Playing;
    return true;
  }
  return false;
}

void GameManager::render(IDisplay& display) {
  if (mode_ == Mode::Menu) {
    renderMenu(display);
  } else {
    activeGame_->render(display);
  }
}

void GameManager::renderMenu(IDisplay& display) {
  display.printLine(0, "Select Game:");
  display.printLine(1, games_[selection_]->name());
}
