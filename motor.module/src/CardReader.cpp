#include "CardReader.h"
#include "GlobalConstants.h"

void CardReader::init() {
    SD.begin(GlobalConstants::READER_CS_PIN);
}

float CardReader::readFloatFromFile(const char *filename, float defaultValue) {
    File file = SD.open(filename);
    if (file) {
        float result = file.parseFloat();
        //Serial.print("File read, result:");
        //Serial.println(result);
        file.close();
        return result;
    } else {
        Serial.println("Error opening file...");
    }

    return defaultValue;
}

int CardReader::readIntFromFile(const char *filename, int defaultValue) {
    File file = SD.open(filename);
    if (file) {
        long result = file.parseInt();
        //Serial.print("File read, result:");
        //Serial.println(result);
        file.close();
        return (int)result;
    } else {
        Serial.println("Error opening file...");
    }

    return defaultValue;
}