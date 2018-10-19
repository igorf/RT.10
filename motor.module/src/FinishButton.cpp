#include "FinishButton.h"

FinishButton::FinishButton(uint8_t pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

boolean FinishButton::isPressed() {
    return digitalRead(pin) == 0;
}

boolean FinishButton::wasPressed() {
    return pressed;
}

void FinishButton::reset() {
    pressed = false;
}

void FinishButton::read() {
    pressed = isPressed();
}