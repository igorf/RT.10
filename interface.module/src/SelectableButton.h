#ifndef INTERFACE_MODULE_SELECTABLEBUTTON_H
#define INTERFACE_MODULE_SELECTABLEBUTTON_H

#include <stdint.h>
#include <Arduino.h>

class SelectableButton {
public:
    SelectableButton(uint8_t signal, uint8_t indicator, int mode);
    void setSelected(int selected);
    bool isPressedNow();
    int getMode();
private:
    uint8_t signalPin;
    uint8_t indicatorPin;
    int mode;

    uint8_t LIGHT_ON_MODE = LOW;
    uint8_t LIGHT_OFF_MODE = HIGH;
};


#endif //INTERFACE_MODULE_SELECTABLEBUTTON_H
