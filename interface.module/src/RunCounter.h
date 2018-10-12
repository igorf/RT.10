#ifndef INTERFACE_MODULE_RUNCOUNTER_H
#define INTERFACE_MODULE_RUNCOUNTER_H


#include <stdint.h>
#include <TM1637Display.h>
#include <Button.h>

class RunCounter {
public:
    void init(uint8_t clk, uint8_t dio, uint8_t resetPin);
    void inc();
    void reset();
    void display();
    void iterate();

private:
    int count = 0;
    TM1637Display *disp;
    Button *resetButton;
};


#endif //INTERFACE_MODULE_RUNCOUNTER_H
