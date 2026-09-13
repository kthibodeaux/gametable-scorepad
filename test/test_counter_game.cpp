#include "test_harness.h"
#include "fakes/FakeEventSink.h"
#include "fakes/FakeDisplay.h"
#include "../src/CounterGame.h"

int test_counter_game() {
  g_testFailures = 0;

  FakeEventSink sink;
  CounterGame game(sink);
  game.onStart();
  ASSERT_EQ(0, sink.lastValue);

  FakeDisplay display;
  game.render(display);
  ASSERT_STREQ("", display.line0.c_str());
  ASSERT_STREQ("Score: 0", display.line1.c_str());

  ASSERT_TRUE(game.onButtonPress(0));
  ASSERT_EQ(1, sink.lastValue);

  ASSERT_TRUE(game.onButtonPress(2));
  ASSERT_EQ(4, sink.lastValue);

  ASSERT_TRUE(game.onButtonPress(7));
  ASSERT_EQ(12, sink.lastValue);

  game.render(display);
  ASSERT_STREQ("Incremented by 8!", display.line0.c_str());
  ASSERT_STREQ("Score: 12", display.line1.c_str());

  return g_testFailures;
}
