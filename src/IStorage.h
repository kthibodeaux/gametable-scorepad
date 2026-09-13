#pragma once
#include <stddef.h>

class IStorage {
public:
  virtual ~IStorage() {}
  virtual bool hasString(const char* key) = 0;
  virtual bool getString(const char* key, char* outBuffer, size_t bufferSize) = 0;
  virtual void putString(const char* key, const char* value) = 0;
};
