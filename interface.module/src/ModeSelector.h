#ifndef INTERFACE_MODULE_MODESELECTOR_H
#define INTERFACE_MODULE_MODESELECTOR_H

#include "SelectableButton.h"
#include "GlobalConstants.h"
#include <CommunicationCommands.h>

class ModeSelector {
public:
    void init(int initialMode);
    void select();
    int getMode();

    static const int MODE_SLOW = CommunicationCommands::RUN_SLOW;
    static const int MODE_FAST = CommunicationCommands::RUN_FAST;
    static const int MODE_RANDOM = 2;

private:
    static const int BUTTONS_COUNT = 3;

    SelectableButton buttons[BUTTONS_COUNT] = {
            SelectableButton(GlobalConstants::SLOW_SIGNAL_PIN, GlobalConstants::SLOW_IND_PIN, MODE_SLOW),
            SelectableButton(GlobalConstants::FAST_SIGNAL_PIN, GlobalConstants::FAST_IND_PIN, MODE_FAST),
            SelectableButton(GlobalConstants::RND_SIGNAL_PIN, GlobalConstants::RND_IND_PIN, MODE_RANDOM),
    };
    int mode = MODE_SLOW;

    void changeSelectedMode(int newMode);
};


#endif //INTERFACE_MODULE_MODESELECTOR_H
