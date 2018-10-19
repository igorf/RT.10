#ifndef ENGINE_MODULE_GLOBALCONSTANTS_H
#define ENGINE_MODULE_GLOBALCONSTANTS_H

#endif //ENGINE_MODULE_GLOBALCONSTANTS_H

class GlobalConstants {
public:
    static const uint8_t SPI_SCK_PIN        = 13;
    static const uint8_t SPI_MISO_PIN       = 12;
    static const uint8_t SPI_MOSI_PIN       = 11;
    static const uint8_t READER_CS_PIN      = 10;

    static const uint8_t LEFT_STOPPER_PIN   = 9;
    static const uint8_t RIGHT_STOPPER_PIN  = 8;

    static const uint8_t PULL_PIN           = 7;
    static const uint8_t DIR_PIN            = 6;

    static const uint8_t INIT_PIN           = 5; // Система инициализирована (светодиод)

    static const uint8_t COMMUNICATOR_PIN   = 4;
};
