#ifndef ENGINE_MODULE_CALIBRATOR_H
#define ENGINE_MODULE_CALIBRATOR_H

#include <Arduino.h>
#include <Button.h>

class Calibrator {
public:
    void init(uint8_t leftPin, uint8_t rightPin);
    void arm();
    void disarm();
    void reset();
    void commandFromCommunicator(int command);
private:
    Button *buttons[2];
    Button *startMeasureButton;
    boolean armed = false;
    boolean measuring = false;
    long result = 0;
    long timeBorder = 0;
    void display();
    void start(Button *startButton);
    void stop();
    void check();
};


#endif //ENGINE_MODULE_CALIBRATOR_H
