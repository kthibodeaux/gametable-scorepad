#include "ScorepadConfig.h"
#include <cstring>

ScorepadConfig::ScorepadConfig(IStorage& storage) : storage_(storage) {}

void ScorepadConfig::loadOrInitialize() {
  if (storage_.hasString(kColorKey)) {
    storage_.getString(kColorKey, color_, sizeof(color_));
  } else {
    setColor(kDefaultColor);
  }
}

void ScorepadConfig::setColor(const char* newColor) {
  std::strncpy(color_, newColor, sizeof(color_) - 1);
  color_[sizeof(color_) - 1] = '\0';
  storage_.putString(kColorKey, color_);
}
