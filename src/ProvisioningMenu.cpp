#include "ProvisioningMenu.h"
#include <cstring>

MenuChoice parseMenuChoice(const char* line) {
  if (std::strcmp(line, "1") == 0) {
    return MenuChoice::ShowColor;
  }
  if (std::strcmp(line, "2") == 0) {
    return MenuChoice::SetColor;
  }
  return MenuChoice::Invalid;
}
