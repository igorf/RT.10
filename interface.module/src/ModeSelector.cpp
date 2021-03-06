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
        if (random(1000) > 500) {
            return MODE_SLOW;
        }
        return MODE_FAST;
    }
    return mode;
}

void ModeSelector::changeSelectedMode(int newMode) {
    for (int i = 0; i < BUTTONS_COUNT; i++) {
        buttons[i].setSelected(buttons[i].getMode() == newMode);
    }
    mode = newMode;
}