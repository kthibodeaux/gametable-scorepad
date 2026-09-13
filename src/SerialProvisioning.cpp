#include "SerialProvisioning.h"
#include "Pins.h"
#include "ProvisioningMenu.h"
#include <Arduino.h>

namespace {

size_t readSerialLine(char* buffer, size_t bufferSize) {
  size_t len = 0;
  while (true) {
    if (Serial.available()) {
      char c = static_cast<char>(Serial.read());
      if (c == '\n' || c == '\r') {
        if (len > 0) break;
        continue;
      }
      if (len < bufferSize - 1) {
        buffer[len++] = c;
      }
    }
  }
  buffer[len] = '\0';
  return len;
}

void printMenu() {
  Serial.println();
  Serial.println("=== Scorepad Provisioning ===");
  Serial.println("1. Show color");
  Serial.println("2. Set color");
  Serial.print("Choice: ");
}

}  // namespace

bool SerialProvisioning::runIfRequested(ScorepadConfig& config, IDisplay& display) {
  bool triggered = digitalRead(kButtonPins[kSerialModeButtonIndexA]) == LOW &&
                   digitalRead(kButtonPins[kSerialModeButtonIndexB]) == LOW;
  if (!triggered) {
    return false;
  }

  display.printLine(0, "Serial Mode");
  display.printLine(1, "See Serial");

  char line[ScorepadConfig::kColorBufferSize];
  while (true) {
    printMenu();
    readSerialLine(line, sizeof(line));

    switch (parseMenuChoice(line)) {
      case MenuChoice::ShowColor:
        Serial.print("Current color: ");
        Serial.println(config.color());
        break;

      case MenuChoice::SetColor: {
        Serial.print("Enter new color: ");
        char newColor[ScorepadConfig::kColorBufferSize];
        readSerialLine(newColor, sizeof(newColor));
        config.setColor(newColor);
        display.printLine(0, "Saved:");
        display.printLine(1, newColor);
        Serial.print("Saved color: ");
        Serial.println(newColor);
        break;
      }

      case MenuChoice::Invalid:
      default:
        Serial.println("Invalid choice.");
        break;
    }
  }
}
