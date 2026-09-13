#include "test_harness.h"
#include "../src/NullEventSink.h"

int test_smoke() {
  g_testFailures = 0;
  NullEventSink sink;
  sink.reportEvent("test", "key", 1);
  ASSERT_TRUE(true);
  return g_testFailures;
}
