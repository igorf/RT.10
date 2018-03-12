cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
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
        "src/"
)

file(GLOB_RECURSE TGT_SRC
        "src/*.cpp"
)

list(APPEND TGT_SRC "../lib/VirtualWire/VirtualWire.cpp")
list(APPEND TGT_SRC "../lib/TM74HC595-4dig-display-master/TM74HC595Display.cpp")
list(APPEND TGT_SRC "../lib/MsTimer2/MsTimer2.cpp")
list(APPEND TGT_SRC "../lib/Button-master/Button.cpp")

set(ARDUINO_DEFAULT_BOARD uno)
#set(ARDUINO_DEFAULT_PORT /dev/tty.usbmodem1411)
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)
set(${CMAKE_PROJECT_NAME}_SKETCH interface_module.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})