#pragma once
#include "IStorage.h"

class ScorepadConfig {
public:
  static constexpr size_t kColorBufferSize = 32;
  static constexpr const char* kColorKey = "color";
  static constexpr const char* kDefaultColor = "unassigned";

  explicit ScorepadConfig(IStorage& storage);

  // Loads the stored color, initializing it to kDefaultColor in storage
  // if nothing has been saved yet. Safe to call once at boot.
  void loadOrInitialize();

  const char* color() const { return color_; }

  // Persists a new color, both to storage and to the in-memory value
  // returned by color().
  void setColor(const char* newColor);

private:
  IStorage& storage_;
  char color_[kColorBufferSize] = {};
};
