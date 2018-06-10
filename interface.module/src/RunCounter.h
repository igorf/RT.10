#ifndef INTERFACE_MODULE_RUNCOUNTER_H
#define INTERFACE_MODULE_RUNCOUNTER_H


#include <stdint.h>
#include <TM74HC595Display.h>
#include <Button.h>

class RunCounter {
public:
    void init(uint8_t sclk, uint8_t rclk, uint8_t dio, uint8_t resetPin);
    void inc();
    void reset();
    void display();
    void iterate();

private:
    int count = 0;
    TM74HC595Display *disp;
    Button *resetButton;
};


#endif //INTERFACE_MODULE_RUNCOUNTER_H
