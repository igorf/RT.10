#ifndef INTERFACE_MODULE_RUNSTARTER_H
#define INTERFACE_MODULE_RUNSTARTER_H


#include <stdint.h>

class RunStarter {
public:
    void init(uint8_t horns, uint8_t start);
    void arm();
    void disarm();
    bool check();
protected:
    bool armed = false;
    uint8_t hornsPin;
    uint8_t startPin;
    const long STATE_DELAY = 700;
    unsigned long lastTime;
};


#endif //INTERFACE_MODULE_RUNSTARTER_H
