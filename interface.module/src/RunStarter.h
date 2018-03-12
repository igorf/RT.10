#ifndef INTERFACE_MODULE_RUNSTARTER_H
#define INTERFACE_MODULE_RUNSTARTER_H

#include <stdint.h>
#include <Button.h>

class RunStarter {
public:
    void init(uint8_t horns, uint8_t start, uint8_t cancel);
    void arm();
    void disarm();
    bool check();

protected:
    Button *hornsButton;
    Button *startButton;
    Button *cancelButton;

    bool ready = true;
    bool hornsArmed = false;

    const int START_SOURCE_HORNS = 100;
    const int START_SOURCE_BUTTON = 200;
    const int START_SOURCE_INIT = -1;

    int startSource = -1;
};


#endif //INTERFACE_MODULE_RUNSTARTER_H
