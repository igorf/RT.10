#ifndef ENGINE_MODULE_ENGINE_H
#define ENGINE_MODULE_ENGINE_H

#include <Arduino.h>
#include <AccelStepper.h>
#include "CardReader.h"
#include "FinishButton.h"

class Engine {
public:
    void init(CardReader* cardReader);
    void command(int command);
private:
    float slowSpeed = 0;
    float fastSpeed = 0;
    int lastStopBorder = 0;
    int reverse = 1;
    boolean isRunning = false;

    CardReader *cardReader;
    AccelStepper *stepper;
    FinishButton *leftStopButton;
    FinishButton *rightStopButton;
    FinishButton *currentStopButton;

    int getDirection();
    FinishButton *getCurrentStopButton(int direction);
    void runSlow();
    void runFast();
    void startEngine(float speed);
    void stop();

    static const int DIRECTION_FORWARD = 1;
    static const int DIRECTION_BACKWARD = -1;

    static const int LEFT_STOPPER = 1;
    static const int RIGHT_STOPPER = 2;
};

#endif