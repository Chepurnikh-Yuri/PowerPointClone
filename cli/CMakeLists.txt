cmake_minimum_required(VERSION 3.10)
project(cli)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cli src/lexer.cpp)
target_include_directories(cli PUBLIC include)