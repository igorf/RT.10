#ifndef INTERFACE_MODULE_RUNSTARTER_H
#define INTERFACE_MODULE_RUNSTARTER_H

#include <stdint.h>
#include <Button.h>

class RunStarter {
public:
    void init();
    void arm();
    void disarm();
    unsigned long check();

protected:
    Button *hornsButton;
    Button *startButton;

    bool ready = true;
    bool hornsArmed = false;

    const int START_SOURCE_HORNS = 100;
    const int START_SOURCE_BUTTON = 200;
    const int START_SOURCE_INIT = -1;
    const unsigned long BUTTON_START_DELAY = 3500;
    const unsigned long HORNS_START_DELAY = 3000;

    int startSource = -1;

    void indicatorOn();
    void indicatorOff();
};


#endif //INTERFACE_MODULE_RUNSTARTER_H
