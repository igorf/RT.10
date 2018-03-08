#include <USBAPI.h>
#include "SelectableButton.h"

SelectableButton::SelectableButton(uint8_t signal, uint8_t indicator, int modeInput) {
    signalPin = signal;
    indicatorPin = indicator;
    mode = modeInput;

    pinMode(indicatorPin, OUTPUT);
    pinMode(signalPin, INPUT);
}

void SelectableButton::setSelected(int selected) {
    if (selected) {
        digitalWrite(indicatorPin, HIGH);
    } else {
        digitalWrite(indicatorPin, LOW);
    }
}