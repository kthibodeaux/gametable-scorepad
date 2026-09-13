#pragma once
#include "../../src/EventSink.h"
#include <string>

class FakeEventSink : public EventSink {
public:
  int callCount = 0;
  std::string lastGameName;
  std::string lastKey;
  long lastValue = 0;

  void reportEvent(const char* gameName, const char* key, long value) override {
    callCount++;
    lastGameName = gameName;
    lastKey = key;
    lastValue = value;
  }
};
