#include <Arduino.h>
#include "RunControl.h"

void RunControl::init(uint8_t stopPin, uint8_t resetPin) {
    stopButton     = new Button(stopPin, false, false, 100);
    resetButton    = new Button(resetPin, false, false, 100);
}

int RunControl::check() {
    stopButton->read();
    if (stopButton->isPressed()) {
        return STOP_COMMAND;
    }

    resetButton->read();
    if (resetButton->isPressed()) {
        return RESET_COMMAND;
    }

    return 0;
}