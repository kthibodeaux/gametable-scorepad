#pragma once
#include "IStorage.h"
#include <Preferences.h>

class Storage : public IStorage {
public:
  void begin();
  bool hasString(const char* key) override;
  bool getString(const char* key, char* outBuffer, size_t bufferSize) override;
  void putString(const char* key, const char* value) override;

private:
  Preferences prefs_;
};
