cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

set(ARDUINO_1_5 True)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME interface_module)
project(${PROJECT_NAME})

link_directories(
        "../lib/VirtualWire"
        "../lib/TM74HC595-4dig-display-master"
        "../lib/MsTimer2"
        "../lib/Button-master"
)

include_directories(
        "../lib/VirtualWire"
        "../lib/TM74HC595-4dig-display-master"
        "../lib/MsTimer2"
        "../lib/Button-master"
        "../common"
        "src/"
)

file(GLOB_RECURSE TGT_SRC
        "src/*.cpp"
        "src/GlobalConstants.h"
)

list(APPEND TGT_SRC "../lib/VirtualWire/VirtualWire.cpp")
list(APPEND TGT_SRC "../lib/TM74HC595-4dig-display-master/TM74HC595Display.cpp")
list(APPEND TGT_SRC "../lib/MsTimer2/MsTimer2.cpp")
list(APPEND TGT_SRC "../lib/Button-master/Button.cpp")

set(${CMAKE_PROJECT_NAME}_BOARD nano)
set(nano.build.mcu atmega328p)
set(nano.upload.speed 57600)
set(ARDUINO_DEFAULT_BOARD nano)
set(ARDUINO_DEFAULT_PORT /dev/cu.wchusbserial1420)
#set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)
set(${CMAKE_PROJECT_NAME}_SKETCH interface_module.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})