cmake_minimum_required(VERSION 3.28)
project(Laba_12_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laba_12_10 main.cpp)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/program.cpp
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})