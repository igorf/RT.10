//
// Created by igor on 13.10.18.
//

#ifndef INTERFACE_MODULE_SCREENRESETTER_H
#define INTERFACE_MODULE_SCREENRESETTER_H


#include <Button.h>
#include "RunCounter.h"

class ScreenResetter {
public:
    void init(RunCounter* cntr);
    void check();
protected:
    Button *resetButton;
    RunCounter *runCounter;
};


#endif //INTERFACE_MODULE_SCREENRESETTER_H
