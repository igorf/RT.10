#include "RunCounter.h"

void RunCounter::init(uint8_t sclk, uint8_t rclk, uint8_t dio, uint8_t resetPin) {
    disp = new TM74HC595Display(sclk, rclk, dio);
    resetButton = new Button(resetPin, false, false, 100);
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
    disp->digit4(count);
}

void RunCounter::iterate() {
    display();
    resetButton->read();
    if (resetButton->isPressed()) {
        reset();
    }
}