#pragma once
#include "../Game.h"
#include "../EventSink.h"

class CounterGame : public Game {
public:
  explicit CounterGame(EventSink& eventSink);

  const char* name() const override;
  void onStart() override;
  bool onButtonPress(uint8_t buttonIndex) override;
  void render(IDisplay& display) override;

private:
  EventSink& eventSink_;
  int score_ = 0;
  int lastIncrement_ = 0;
  bool hasIncremented_ = false;
};
