#include "RunCounter.h"

void RunCounter::init(uint8_t sclk, uint8_t rclk, uint8_t dio) {
    disp = new TM74HC595Display(sclk, rclk, dio);
    display();
}

void RunCounter::inc() {
    count ++;
    display();
}

void RunCounter::reset() {
    count = 0;
    display();
}

void RunCounter::display() {
    disp->digit4(count);
}