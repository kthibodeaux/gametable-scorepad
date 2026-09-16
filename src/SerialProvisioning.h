#pragma once
#include "ScorepadConfig.h"
#include "IDisplay.h"
#include "ButtonReader.h"

class SerialProvisioning {
public:
  // Checks whether the boot-hold button combo is held; if so, drives an
  // interactive Serial menu (show/set scorepadColor) that runs until the
  // device is reset -- there's no path back to normal boot from here, by
  // design, matching the rest of the platform's power-cycle-to-exit model.
  // Returns false immediately if the combo isn't held.
  bool runIfRequested(ButtonReader& buttons, ScorepadConfig& config, IDisplay& display);
};
