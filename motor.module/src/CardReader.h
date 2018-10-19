#include "SPI.h"
#include "SD.h"

#ifndef ENGINE_MODULE_CARDREADER_H
#define ENGINE_MODULE_CARDREADER_H


class CardReader {
public:
    void init();
    float readFloatFromFile(const char* file, float defaultValue = 0.0);
    int readIntFromFile(const char* file, int defaultValue = 0);
};


#endif //ENGINE_MODULE_CARDREADER_H
