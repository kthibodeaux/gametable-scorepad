#pragma once
#include "../../src/EventSink.h"
#include <string>

class FakeEventSink : public EventSink {
public:
  int callCount = 0;
  std::string lastGameName;
  std::string lastKey;
  int lastValue = 0;

  void reportEvent(const char* gameName, const char* key, int value) override {
    callCount++;
    lastGameName = gameName;
    lastKey = key;
    lastValue = value;
  }
};
