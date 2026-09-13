#include "src/GameManager.h"
#include "src/games/CounterGame.h"
#include "src/NullEventSink.h"
#include "src/ButtonReader.h"
#include "src/Display.h"

NullEventSink eventSink;
CounterGame counterGame(eventSink);
Game* games[] = {&counterGame};

GameManager gameManager(games, 1);
ButtonReader buttonReader;
Display display;

void setup() {
  Serial.begin(115200);
  buttonReader.begin();
  display.begin();
  gameManager.render(display);
}

void loop() {
  uint8_t pressedIndex;
  if (buttonReader.poll(pressedIndex)) {
    if (gameManager.handleButtonPress(pressedIndex)) {
      gameManager.render(display);
    }
  }
}
