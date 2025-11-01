cmake_minimum_required(VERSION 3.10)
project(power_point_clone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES
"${PROJECT_SOURCE_DIR}/src/*.cpp"
"${PROJECT_SOURCE_DIR}/main.cpp"
)

add_executable(power_point_clone ${SRC_FILES})

target_include_directories(power_point_clone PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/parser
    ${PROJECT_SOURCE_DIR}/include/models
)
