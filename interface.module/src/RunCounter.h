#ifndef INTERFACE_MODULE_RUNCOUNTER_H
#define INTERFACE_MODULE_RUNCOUNTER_H


#include <stdint.h>
#include <TM74HC595Display.h>

class RunCounter {
public:
    void init(uint8_t sclk, uint8_t rclk, uint8_t dio);
    void inc();
    void reset();
    void display();

private:
    int count = 0;
    TM74HC595Display *disp;
};


#endif //INTERFACE_MODULE_RUNCOUNTER_H
