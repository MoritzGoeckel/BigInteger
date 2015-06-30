cmake_minimum_required(VERSION 3.2)
project(CPP_BigInteger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Main.cpp)

add_executable(CPP_BigInteger ${SOURCE_FILES} BigInteger.h BigInteger.cpp)