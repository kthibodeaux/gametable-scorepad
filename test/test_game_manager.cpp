#include "test_harness.h"
#include "fakes/FakeDisplay.h"
#include "fakes/FakeEventSink.h"
#include "../src/games/CounterGame.h"
#include "../src/GameManager.h"

int test_game_manager() {
  g_testFailures = 0;

  FakeEventSink sink;
  CounterGame counter(sink, "Red");
  Game* games[] = {&counter};
  GameManager manager(games, 1);
  FakeDisplay display;

  manager.render(display);
  ASSERT_STREQ("Select Game:", display.line0.c_str());
  ASSERT_STREQ("Counter", display.line1.c_str());

  ASSERT_TRUE(manager.handleButtonPress(0));
  ASSERT_TRUE(manager.handleButtonPress(2));
  manager.render(display);
  ASSERT_STREQ("Color: Red", display.line0.c_str());
  ASSERT_STREQ("Score: 0", display.line1.c_str());

  ASSERT_TRUE(manager.handleButtonPress(0));
  manager.render(display);
  ASSERT_STREQ("Incremented by 1!", display.line0.c_str());
  ASSERT_STREQ("Score: 1", display.line1.c_str());

  return g_testFailures;
}
