#include "ModeSelector.h"

void ModeSelector::select() {

}

void ModeSelector::init(int initialMode) {
    buttons[initialMode].setSelected(true);
    mode = initialMode;
}

int ModeSelector::getMode() {
    return mode;
}