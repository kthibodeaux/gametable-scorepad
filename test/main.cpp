#include <cstdio>
#include "test_harness.h"

int test_smoke();
int test_counter_game();

int main() {
  int failures = 0;
  failures += test_smoke();
  failures += test_counter_game();
  if (failures == 0) {
    std::printf("All tests passed.\n");
  } else {
    std::printf("%d test failure(s).\n", failures);
  }
  return failures;
}
