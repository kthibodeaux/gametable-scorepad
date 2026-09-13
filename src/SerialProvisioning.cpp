#include "SerialProvisioning.h"
#include "Pins.h"
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

}  // namespace

bool SerialProvisioning::runIfRequested(ScorepadConfig& config, IDisplay& display) {
  bool triggered = digitalRead(kButtonPins[kSerialModeButtonIndexA]) == LOW &&
                   digitalRead(kButtonPins[kSerialModeButtonIndexB]) == LOW;
  if (!triggered) {
    return false;
  }

  display.printLine(0, "Serial Mode");
  display.printLine(1, "Send color...");
  Serial.println("Serial provisioning mode. Send a color and press enter.");

  char buffer[ScorepadConfig::kColorBufferSize];
  readSerialLine(buffer, sizeof(buffer));
  config.setColor(buffer);

  display.printLine(0, "Saved:");
  display.printLine(1, buffer);
  Serial.print("Saved color: ");
  Serial.println(buffer);
  delay(1500);

  return true;
}
