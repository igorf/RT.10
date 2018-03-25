#ifndef ENGINE_MODULE_ENGINE_H
#define ENGINE_MODULE_ENGINE_H

#include <Arduino.h>
#include <AFMotor.h>
#include <AccelStepper.h>
#include <Button.h>

class Engine {
public:
    void init(AccelStepper *stepperPtr, int slowRPM, int fastRPM, uint8_t leftButton, uint8_t rightButton);
    void command(int command);
    boolean running();
private:
    int slowSpeed = 0;
    int fastSpeed = 0;
    int lastStopBorder = 0;
    AccelStepper *stepper;
    boolean isRunning = false;
    Button *leftStopButton;
    Button *rightStopButton;
    Button *currentStopButton;

    int getDirection();
    Button *getCurrentStopButton(int direction);
    void runSlow();
    void runFast();
    void startEngine(int speed);
    void stop();

    static const int DIRECTION_FORWARD = 1;
    static const int DIRECTION_BACKWARD = -1;

    static const int LEFT_STOPPER = 1;
    static const int RIGHT_STOPPER = 2;
};

#endif