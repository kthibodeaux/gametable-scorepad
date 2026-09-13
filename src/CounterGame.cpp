#include "CounterGame.h"
#include <cstdio>

CounterGame::CounterGame(EventSink& eventSink) : eventSink_(eventSink) {}

const char* CounterGame::name() const { return "Counter"; }

void CounterGame::onStart() {
  score_ = 0;
  lastIncrement_ = 0;
  hasIncremented_ = false;
  eventSink_.reportEvent(name(), "score", score_);
}

bool CounterGame::onButtonPress(uint8_t buttonIndex) {
  long increment = static_cast<long>(buttonIndex) + 1;
  score_ += increment;
  lastIncrement_ = increment;
  hasIncremented_ = true;
  eventSink_.reportEvent(name(), "score", score_);
  return true;
}

void CounterGame::render(IDisplay& display) {
  if (hasIncremented_) {
    char message[32];
    std::snprintf(message, sizeof(message), "Incremented by %ld!", lastIncrement_);
    display.printLine(0, message);
  } else {
    display.printLine(0, "");
  }
  char line[32];
  std::snprintf(line, sizeof(line), "Score: %ld", score_);
  display.printLine(1, line);
}
