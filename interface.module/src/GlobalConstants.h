//
// Created by Игорь Федоренко on 10.06.18.
//

#ifndef INTERFACE_MODULE_GLOBALCONSTANTS_H
#define INTERFACE_MODULE_GLOBALCONSTANTS_H


class GlobalConstants {
public:
    static const uint8_t LIGHT_MODE_ON = LOW;
    static const uint8_t LIGHT_MODE_OFF = HIGH;

    static const uint8_t STOP_PIN          = 2;
    static const uint8_t START_PIN         = 3;
    static const uint8_t RESET_PIN         = 4;
    static const uint8_t HORNS_PIN         = 5;
    static const uint8_t CANCEL_PIN        = 6;
    static const uint8_t CNT_SCLK_PIN      = 8;
    static const uint8_t CNT_RCLK_PIN      = 9;
    static const uint8_t CNT_DIO_PIN       = 10;
    static const uint8_t SENDER_PIN        = 11;
    static const uint8_t START_LIGHT_PIN   = A4;
    static const uint8_t COUNT_RESET_PIN   = A5;

    static const unsigned long RUN_DELAY = 4000;
};


#endif //INTERFACE_MODULE_GLOBALCONSTANTS_H
