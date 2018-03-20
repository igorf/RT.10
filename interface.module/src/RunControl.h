#ifndef INTERFACE_MODULE_RUNCONTROL_H
#define INTERFACE_MODULE_RUNCONTROL_H

#include <stdint.h>
#include <Button.h>

class RunControl {
public:
    void init(uint8_t stop, uint8_t reset);
    int check();

protected:
    Button *stopButton;
    Button *resetButton;

private:
    const int STOP_COMMAND = 200;
    const int RESET_COMMAND = 300;
};


#endif //INTERFACE_MODULE_RUNCONTROL_H
