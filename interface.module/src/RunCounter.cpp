#include "RunCounter.h"

void RunCounter::init(uint8_t clk, uint8_t dio) {
    disp = new TM1637Display(clk, dio);
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    disp->setSegments(data);
    disp->setBrightness(0x0f);
    display();
}

void RunCounter::inc() {
    count ++;
    display();
}

void RunCounter::reset() {
    count = 0;
}

void RunCounter::display() {
    disp->showNumberDec(count, false, 4, 0);
}