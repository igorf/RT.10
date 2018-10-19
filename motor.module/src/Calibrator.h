#ifndef ENGINE_MODULE_CALIBRATOR_H
#define ENGINE_MODULE_CALIBRATOR_H

#include <Arduino.h>
#include "FinishButton.h"

class Calibrator {
public:
    void init(uint8_t leftPin, uint8_t rightPin);
    void arm();
    void disarm();
    void reset();
    void commandFromCommunicator(int command);
private:
    FinishButton *buttons[2];
    FinishButton *startMeasureButton;
    boolean armed = false;
    boolean measuring = false;
    long result = 0;
    long timeBorder = 0;
    void display();
    void start(FinishButton *startButton);
    void stop();
    void check();
};


#endif //ENGINE_MODULE_CALIBRATOR_H
