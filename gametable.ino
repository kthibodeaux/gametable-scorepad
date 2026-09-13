#include "src/GameManager.h"
#include "src/games/CounterGame.h"
#include "src/NullEventSink.h"
#include "src/ButtonReader.h"
#include "src/Display.h"
#include "src/Storage.h"
#include "src/ScorepadConfig.h"
#include "src/SerialProvisioning.h"
#include <cstring>

NullEventSink eventSink;
CounterGame counterGame(eventSink);
Game* games[] = {&counterGame};

GameManager gameManager(games, 1);
ButtonReader buttonReader;
Display display;
Storage storage;
ScorepadConfig scorepadConfig(storage);
SerialProvisioning serialProvisioning;

char scorepadColor[ScorepadConfig::kColorBufferSize];

void setup() {
  Serial.begin(115200);
  buttonReader.begin();
  display.begin();
  storage.begin();

  if (!serialProvisioning.runIfRequested(scorepadConfig, display)) {
    scorepadConfig.loadOrInitialize();
  }
  strncpy(scorepadColor, scorepadConfig.color(), sizeof(scorepadColor) - 1);
  scorepadColor[sizeof(scorepadColor) - 1] = '\0';

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
