#include "CounterGame.h"
#include <cstdio>

CounterGame::CounterGame(EventSink& eventSink, const char* scorepadColor)
    : eventSink_(eventSink), scorepadColor_(scorepadColor) {}

const char* CounterGame::name() const { return "Counter"; }

void CounterGame::onStart() {
  score_ = 0;
  lastIncrement_ = 0;
  hasIncremented_ = false;
  eventSink_.reportEvent(name(), "score", score_);
}

bool CounterGame::onButtonPress(uint8_t buttonIndex) {
  int increment = static_cast<int>(buttonIndex) + 1;
  score_ += increment;
  lastIncrement_ = increment;
  hasIncremented_ = true;
  eventSink_.reportEvent(name(), "score", score_);
  return true;
}

void CounterGame::render(IDisplay& display) {
  if (hasIncremented_) {
    char message[32];
    std::snprintf(message, sizeof(message), "Incremented by %d!", lastIncrement_);
    display.printLine(0, message);
  } else {
    char message[32];
    std::snprintf(message, sizeof(message), "Color: %s", scorepadColor_);
    display.printLine(0, message);
  }
  char line[32];
  std::snprintf(line, sizeof(line), "Score: %d", score_);
  display.printLine(1, line);
}
