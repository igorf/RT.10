#include <Arduino.h>
#include "src/ModeSelector.h"

ModeSelector modeSelector;

void setup() {
    modeSelector.init(ModeSelector::MODE_SLOW);
}

void loop() {
    modeSelector.select();
    int mode = modeSelector.getMode();
    delay(1);
}