
cmake_minimum_required(VERSION 3.15)
project(OTA_platform_TC375 C)
set(CMAKE_C_STANDARD 11)
add_definitions(-DOTA_PLATFORM_NAME=\"OTA_platform_TC375\" -DOTA_VERSION=\"0.0.0\")
add_subdirectory(ccu/app)
add_subdirectory(ccu/bootloader)
add_subdirectory(zonal_gateway/app)
add_subdirectory(zonal_gateway/bootloader)
add_subdirectory(ecu/app)
add_subdirectory(ecu/bootloader)

