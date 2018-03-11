#ifndef INTERFACE_MODULE_MODESELECTOR_H
#define INTERFACE_MODULE_MODESELECTOR_H

#include "SelectableButton.h"

class ModeSelector {
public:
    void init(int initialMode);
    void select();
    int getMode();

    static const int MODE_SLOW = 0;
    static const int MODE_FAST = 1;
    static const int MODE_RANDOM = 2;

private:
    static const int BUTTONS_COUNT = 3;

    SelectableButton buttons[BUTTONS_COUNT] = {
            SelectableButton(A0, A1, MODE_SLOW),
            SelectableButton(A2, A3, MODE_FAST),
            SelectableButton(A4, A5, MODE_RANDOM),
    };
    int mode = MODE_SLOW;

    void changeSelectedMode(int newMode);
};


#endif //INTERFACE_MODULE_MODESELECTOR_H
