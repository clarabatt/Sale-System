cmake_minimum_required(VERSION 3.24)
project(MS4)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS4 main.cpp NonPerishable.cpp Error.cpp Item.cpp Date.cpp PosIO.cpp Perishable.cpp Perishable.h)
