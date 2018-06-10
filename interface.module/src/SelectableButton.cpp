#include "SelectableButton.h"

SelectableButton::SelectableButton(uint8_t signal, uint8_t indicator, int modeInput) {
    signalPin = signal;
    indicatorPin = indicator;
    mode = modeInput;

    pinMode(indicatorPin, OUTPUT);
    pinMode(signalPin, INPUT);
    digitalWrite(signalPin, SelectableButton::LIGHT_OFF_MODE);
}

void SelectableButton::setSelected(int selected) {
    if (selected) {
        digitalWrite(indicatorPin, SelectableButton::LIGHT_ON_MODE);
    } else {
        digitalWrite(indicatorPin, SelectableButton::LIGHT_OFF_MODE);
    }
}

bool SelectableButton::isPressedNow() {
    return digitalRead(signalPin) == HIGH;
}

int SelectableButton::getMode() {
    return mode;
}