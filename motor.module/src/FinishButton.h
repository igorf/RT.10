#ifndef ENGINE_MODULE_FINISHBUTTON_H
#define ENGINE_MODULE_FINISHBUTTON_H

#include <Arduino.h>

class FinishButton {
public:
    FinishButton(uint8_t pin);
    boolean isPressed();
    boolean wasPressed();
    void reset();
    void read();
private:
    uint8_t pin;
    boolean pressed = false;
};


#endif //ENGINE_MODULE_FINISHBUTTON_H
