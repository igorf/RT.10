cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)

set(ARDUINO_1_5 True)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME engine_module)
set(SD_RECURSE True)

project(${PROJECT_NAME})

link_directories(
        "../lib/VirtualWire"
        "../lib/AccelStepper"
)

include_directories(
        "../lib/VirtualWire"
        "../lib/AccelStepper"
        "../common"
        "src/"
)

file(GLOB_RECURSE TGT_SRC
        "src/*.cpp"
)

list(APPEND TGT_SRC "../lib/VirtualWire/VirtualWire.cpp")
list(APPEND TGT_SRC "../lib/Button-master/Button.cpp")
list(APPEND TGT_SRC "../lib/adafruit-Adafruit-Motor-Shield-library-99381df/AFMotor.cpp")
list(APPEND TGT_SRC "../lib/AccelStepper/AccelStepper.cpp")

set(${CMAKE_PROJECT_NAME}_BOARD uno)
set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/cu.usbmodem14201)
#set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)
set(${CMAKE_PROJECT_NAME}_SKETCH motor_module.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
