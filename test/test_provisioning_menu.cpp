#include "test_harness.h"
#include "../src/ProvisioningMenu.h"

int test_provisioning_menu() {
  g_testFailures = 0;

  ASSERT_TRUE(parseMenuChoice("1") == MenuChoice::ShowColor);
  ASSERT_TRUE(parseMenuChoice("2") == MenuChoice::SetColor);
  ASSERT_TRUE(parseMenuChoice("3") == MenuChoice::Invalid);
  ASSERT_TRUE(parseMenuChoice("") == MenuChoice::Invalid);
  ASSERT_TRUE(parseMenuChoice("show") == MenuChoice::Invalid);

  return g_testFailures;
}
