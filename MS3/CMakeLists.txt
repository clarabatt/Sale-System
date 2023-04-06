cmake_minimum_required(VERSION 3.24)
project(MS3)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS3 Item.cpp main.cpp Error.cpp PosIO.cpp)
