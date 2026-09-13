#pragma once
#include "ScorepadConfig.h"
#include "IDisplay.h"

class SerialProvisioning {
public:
  // Checks whether the boot-hold button combo is held; if so, blocks
  // waiting for a color over Serial, saves it via config, and shows
  // status on display. Returns true if provisioning mode was entered.
  bool runIfRequested(ScorepadConfig& config, IDisplay& display);
};
