cmake_minimum_required(VERSION 3.25)
project(MS5)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS5 main.cpp main.cpp NonPerishable.cpp Error.cpp Item.cpp Date.cpp PosIO.cpp Perishable.cpp PosApp.cpp Utils.cpp)
