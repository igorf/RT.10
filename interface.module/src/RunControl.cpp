#include <Arduino.h>
#include "RunControl.h"
#include "GlobalConstants.h"

void RunControl::init() {
    stopButton     = new Button(GlobalConstants::STOP_PIN, false, false, 100);
    resetButton    = new Button(GlobalConstants::RESET_PIN, false, false, 100);
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