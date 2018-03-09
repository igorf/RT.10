#include <USBAPI.h>
#include "ModeSelector.h"

void ModeSelector::select() {
    for (int i = 0; i < BUTTONS_COUNT; i++) {
        if (buttons[i].isPressedNow()) {
            if (mode != buttons[i].getMode()) {
                changeSelectedMode(buttons[i].getMode());
                return;
            }
        }
    }
}

void ModeSelector::init(int initialMode) {
    buttons[initialMode].setSelected(true);
    mode = initialMode;
}

int ModeSelector::getMode() {
    if (mode == MODE_RANDOM) {
        return static_cast<int>(random(MODE_SLOW, MODE_FAST + 1));
    }
    return mode;
}

void ModeSelector::changeSelectedMode(int newMode) {
    for (int i = 0; i < BUTTONS_COUNT; i++) {
        buttons[i].setSelected(buttons[i].getMode() == newMode);
    }
}