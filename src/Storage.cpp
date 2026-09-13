#include "Storage.h"

namespace {
constexpr const char* kNamespace = "scorepad";
}

void Storage::begin() {
  prefs_.begin(kNamespace, false);
}

bool Storage::hasString(const char* key) {
  return prefs_.isKey(key);
}

bool Storage::getString(const char* key, char* outBuffer, size_t bufferSize) {
  return prefs_.getString(key, outBuffer, bufferSize) > 0;
}

void Storage::putString(const char* key, const char* value) {
  prefs_.putString(key, value);
}
