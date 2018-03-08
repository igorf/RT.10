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
    SelectableButton buttons[3] = {
            SelectableButton(1, 2, MODE_SLOW),
            SelectableButton(7, 8, MODE_FAST),
            SelectableButton(3, 4, MODE_RANDOM),
    };
    int mode = MODE_SLOW;
};


#endif //INTERFACE_MODULE_MODESELECTOR_H
