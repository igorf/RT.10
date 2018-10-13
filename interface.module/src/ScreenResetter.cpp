#include "ScreenResetter.h"
#include "GlobalConstants.h"

void ScreenResetter::init(RunCounter* cntr) {
    resetButton = new Button(GlobalConstants::COUNT_RESET_PIN, false, false, 200);
    runCounter = cntr;
}

void ScreenResetter::check() {
    resetButton->read();
    if (resetButton->isPressed() && runCounter != nullptr) {
        runCounter->reset();
    }
}