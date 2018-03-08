cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME engine_module)
project(${PROJECT_NAME})

include_directories(
        "src/"
)

file(GLOB_RECURSE TGT_SRC
        "src/*.cpp"
)

set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/tty.usbmodem1411)
set(${CMAKE_PROJECT_NAME}_SKETCH engine_module.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})