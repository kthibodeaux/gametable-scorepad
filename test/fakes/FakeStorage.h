#pragma once
#include "../../src/IStorage.h"
#include <cstring>
#include <map>
#include <string>

class FakeStorage : public IStorage {
public:
  bool hasString(const char* key) override {
    return values.find(key) != values.end();
  }

  bool getString(const char* key, char* outBuffer, size_t bufferSize) override {
    auto it = values.find(key);
    if (it == values.end()) {
      return false;
    }
    std::strncpy(outBuffer, it->second.c_str(), bufferSize - 1);
    outBuffer[bufferSize - 1] = '\0';
    return true;
  }

  void putString(const char* key, const char* value) override {
    values[key] = value;
  }

  std::map<std::string, std::string> values;
};
