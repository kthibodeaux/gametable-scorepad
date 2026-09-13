#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
g++ -std=c++17 -Wall -Wextra -I ../src -o /tmp/gametable_tests \
  main.cpp \
  test_smoke.cpp
/tmp/gametable_tests
