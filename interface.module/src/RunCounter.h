#ifndef INTERFACE_MODULE_RUNCOUNTER_H
#define INTERFACE_MODULE_RUNCOUNTER_H


#include <stdint.h>
#include <TM1637Display.h>
#include <Button.h>

class RunCounter {
public:
    void init();
    void inc();
    void reset();
    void display();

private:
    int count = 0;
    TM1637Display *disp;
};


#endif //INTERFACE_MODULE_RUNCOUNTER_H
