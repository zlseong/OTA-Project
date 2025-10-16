
cmake_minimum_required(VERSION 3.15)
project(app C)
set(CMAKE_C_STANDARD 11)
add_executable(${PROJECT_NAME}
    src/main.c
    ../../common/ota_proto/ota_common.c
    ../../common/flash/flash_api.c
    ../../common/net/net_client.c
)
target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ../../common/include
    ../../common/flash
    ../../common/net
)

