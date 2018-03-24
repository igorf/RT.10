#include <Arduino.h>
#include "RunControl.h"

void RunControl::init(uint8_t stopPin, uint8_t resetPin) {
    stopButton     = new Button(stopPin, false, false, 100);
    resetButton    = new Button(resetPin, false, false, 100);
    stopReady = true;
    resetReady = true;
}

int RunControl::check() {
    stopButton->read();
    if (stopButton->isPressed() && stopReady) {
        stopReady = false;
        return STOP_COMMAND;
    }

    if (stopButton->isReleased() && !stopReady) {
        stopReady = true;
        return 0;
    }

    resetButton->read();
    if (resetButton->isPressed() && resetReady) {
        resetReady = false;
        return RESET_COMMAND;
    }

    if (resetButton->isReleased() && !resetReady) {
        resetReady = true;
        return 0;
    }

    return 0;
}