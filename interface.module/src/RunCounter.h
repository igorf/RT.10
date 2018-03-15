#ifndef INTERFACE_MODULE_RUNCOUNTER_H
#define INTERFACE_MODULE_RUNCOUNTER_H


#include <stdint.h>
#include <TM74HC595Display.h>

class RunCounter {
public:
    void init(uint8_t sclk, uint8_t rclk, uint8_t dio);
    void inc();
    void reset();

private:
    int count = 0;
    void display();
    TM74HC595Display *disp;

    unsigned char DIGITS[10] = {
            0xC0,0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90
    };
    unsigned char DOT = 0xFE;
};


#endif //INTERFACE_MODULE_RUNCOUNTER_H
