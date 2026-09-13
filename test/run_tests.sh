#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
g++ -std=c++17 -Wall -Wextra -I ../src -o /tmp/gametable_tests \
  main.cpp \
  test_smoke.cpp \
  test_counter_game.cpp \
  ../src/games/CounterGame.cpp \
  test_game_manager.cpp \
  ../src/GameManager.cpp \
  test_scorepad_config.cpp \
  ../src/ScorepadConfig.cpp \
  test_provisioning_menu.cpp \
  ../src/ProvisioningMenu.cpp
/tmp/gametable_tests
