#include "test_harness.h"
#include "fakes/FakeStorage.h"
#include "../src/ScorepadConfig.h"

int test_scorepad_config() {
  g_testFailures = 0;

  FakeStorage storage;
  ScorepadConfig config(storage);

  ASSERT_TRUE(!storage.hasString("color"));
  config.loadOrInitialize();
  ASSERT_STREQ("unassigned", config.color());
  ASSERT_TRUE(storage.hasString("color"));
  ASSERT_STREQ("unassigned", storage.values["color"].c_str());

  config.setColor("Red");
  ASSERT_STREQ("Red", config.color());
  ASSERT_STREQ("Red", storage.values["color"].c_str());

  FakeStorage prePopulatedStorage;
  prePopulatedStorage.putString("color", "Blue");
  ScorepadConfig existingConfig(prePopulatedStorage);
  existingConfig.loadOrInitialize();
  ASSERT_STREQ("Blue", existingConfig.color());

  return g_testFailures;
}
