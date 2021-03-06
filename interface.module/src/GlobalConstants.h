//
// Created by Игорь Федоренко on 10.06.18.
//

#ifndef INTERFACE_MODULE_GLOBALCONSTANTS_H
#define INTERFACE_MODULE_GLOBALCONSTANTS_H


class GlobalConstants {
public:
    static const uint8_t LIGHT_MODE_ON = LOW;
    static const uint8_t LIGHT_MODE_OFF = HIGH;

    // Pinout
    static const uint8_t STOP_PIN          = 2;
    static const uint8_t START_PIN         = 3;
    static const uint8_t RESET_PIN         = 4;
    static const uint8_t HORNS_PIN         = 5;
    static const uint8_t CANCEL_PIN        = 6;
    static const uint8_t CNT_SCLK_PIN      = 8;
    static const uint8_t CNT_RCLK_PIN      = 9;
    static const uint8_t CNT_DIO_PIN       = 10;
    static const uint8_t SENDER_PIN        = 11;
    static const uint8_t START_LIGHT_PIN   = 1;
    static const uint8_t COUNT_RESET_PIN   = 13;
    static const uint8_t SLOW_SIGNAL_PIN   = A0;
    static const uint8_t SLOW_IND_PIN      = A1;
    static const uint8_t FAST_SIGNAL_PIN   = A2;
    static const uint8_t FAST_IND_PIN      = A3;
    static const uint8_t RND_SIGNAL_PIN    = 7;
    static const uint8_t RND_IND_PIN       = 12;
    static const uint8_t I2C_SDA           = A4;
    static const uint8_t I2C_SCL           = A5;

    // Delay
    static const unsigned long RUN_DELAY = 4000;
};


#endif //INTERFACE_MODULE_GLOBALCONSTANTS_H
