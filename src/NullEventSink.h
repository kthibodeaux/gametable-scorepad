#pragma once
#include "EventSink.h"

// Seam for a future networked EventSink (e.g. reporting to a game server).
// No-op today since every scorepad is standalone.
class NullEventSink : public EventSink {
public:
  void reportEvent(const char*, const char*, long) override {}
};
