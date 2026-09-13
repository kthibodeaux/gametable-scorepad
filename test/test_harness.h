#pragma once
#include <cstdio>
#include <string>

inline int g_testFailures = 0;

#define ASSERT_TRUE(cond) \
  do { \
    if (!(cond)) { \
      std::printf("  FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
      g_testFailures++; \
    } \
  } while (0)

#define ASSERT_EQ(expected, actual) \
  do { \
    auto _e = (expected); \
    auto _a = (actual); \
    if (!(_e == _a)) { \
      std::printf("  FAIL %s:%d: expected %s == %s\n", __FILE__, __LINE__, #expected, #actual); \
      g_testFailures++; \
    } \
  } while (0)

#define ASSERT_STREQ(expected, actual) \
  do { \
    if (std::string(expected) != std::string(actual)) { \
      std::printf("  FAIL %s:%d: expected \"%s\" == \"%s\"\n", __FILE__, __LINE__, expected, actual); \
      g_testFailures++; \
    } \
  } while (0)
