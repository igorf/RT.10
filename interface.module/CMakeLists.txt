cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME interface_module)
project(${PROJECT_NAME})

link_directories(
        "../lib/VirtualWire"
)

include_directories(
        "../lib/VirtualWire"
        "src/"
)

file(GLOB_RECURSE TGT_SRC
        "src/*.cpp"
        "interface_module.ino"
)

list(APPEND TGT_SRC "../lib/VirtualWire/VirtualWire.cpp")

set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/tty.usbmodem1411)
set(${CMAKE_PROJECT_NAME}_SKETCH interface_module.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})