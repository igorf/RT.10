#include "RunCounter.h"

void RunCounter::init(uint8_t clk, uint8_t dio) {
    disp = new TM1637Display(clk, dio);
    disp->setBrightness(0x0f);
    display();
}

void RunCounter::inc() {
    count ++;
    if (count >= 10000) {
        count = 1;
    }
    display();
}

void RunCounter::reset() {
    count = 0;
    display();
}

void RunCounter::display() {
    disp->showNumberDec(count, false, 4, 0);
}