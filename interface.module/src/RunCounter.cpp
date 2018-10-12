#include "RunCounter.h"

void RunCounter::init(uint8_t clk, uint8_t dio, uint8_t resetPin) {
    disp = new TM1637Display(clk, dio);
    resetButton = new Button(resetPin, false, false, 100);
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
    disp->setSegments(data);
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

void RunCounter::iterate() {
    display();
    resetButton->read();
    if (resetButton->isPressed()) {
        reset();
    }
}