#include <USBAPI.h>
#include "SelectableButton.h"

SelectableButton::SelectableButton(uint8_t signal, uint8_t indicator, int modeInput) {
    signalPin = signal;
    indicatorPin = indicator;
    mode = modeInput;

    pinMode(indicatorPin, OUTPUT);
    pinMode(signalPin, INPUT);
    digitalWrite(signalPin, LOW);
}

void SelectableButton::setSelected(int selected) {
    if (selected) {
        digitalWrite(indicatorPin, HIGH);
    } else {
        digitalWrite(indicatorPin, LOW);
    }
}

boolean SelectableButton::isPressedNow() {
    /*
    return digitalRead(signalPin) == HIGH;
     */
    boolean pressed = digitalRead(signalPin) == HIGH;
    if (pressed) {
        Serial.print(signalPin);
        Serial.print("\n");
    }
    return pressed;
}

int SelectableButton::getMode() {
    return mode;
}