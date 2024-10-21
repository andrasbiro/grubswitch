cmake_minimum_required(VERSION 3.13...3.27)

set(PROJECT_NAME grubswitch)


#pull in the PICO SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#init the sdk
pico_sdk_init()

add_executable(${PROJECT_NAME}
        src/main.c
        src/msc_disk.c
        src/usb_descriptors.c
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        src/)

#pull in pico_stdlib
target_link_libraries(${PROJECT_NAME} pico_stdlib tinyusb_device)

# pico_enable_stdio_usb(${PROJECT_NAME} 0)
# pico_enable_stdio_uart(${PROJECT_NAME} 1)

#create uf2
pico_add_extra_outputs(${PROJECT_NAME})