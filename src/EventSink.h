#pragma once

class EventSink {
public:
  virtual ~EventSink() {}
  virtual void reportEvent(const char* gameName, const char* key, long value) = 0;
};
