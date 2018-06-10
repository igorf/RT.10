#include "SelectableButton.h"
#include "GlobalConstants.h"

SelectableButton::SelectableButton(uint8_t signal, uint8_t indicator, int modeInput) {
    signalPin = signal;
    indicatorPin = indicator;
    mode = modeInput;

    pinMode(indicatorPin, OUTPUT);
    pinMode(signalPin, INPUT);
    digitalWrite(signalPin, GlobalConstants::LIGHT_MODE_OFF);
}

void SelectableButton::setSelected(int selected) {
    if (selected) {
        digitalWrite(indicatorPin, GlobalConstants::LIGHT_MODE_ON);
    } else {
        digitalWrite(indicatorPin, GlobalConstants::LIGHT_MODE_OFF);
    }
}

bool SelectableButton::isPressedNow() {
    return digitalRead(signalPin) == HIGH;
}

int SelectableButton::getMode() {
    return mode;
}