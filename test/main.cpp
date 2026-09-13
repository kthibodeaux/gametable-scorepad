#include <cstdio>
#include "test_harness.h"

int test_smoke();

int main() {
  int failures = 0;
  failures += test_smoke();
  if (failures == 0) {
    std::printf("All tests passed.\n");
  } else {
    std::printf("%d test failure(s).\n", failures);
  }
  return failures;
}
