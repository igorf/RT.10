#include "RunCounter.h"
#include "GlobalConstants.h"

void RunCounter::init() {
    disp = new TM1637Display(GlobalConstants::CNT_SCLK_PIN, GlobalConstants::CNT_DIO_PIN);
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