
cmake_minimum_required(VERSION 3.15)
project(boot C)
set(CMAKE_C_STANDARD 11)
add_executable(${PROJECT_NAME}
    src/boot_main.c
    ../../common/flash/flash_api.c
)
target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ../../common/include
    ../../common/flash
)

