cmake_minimum_required(VERSION 3.24)
project(MS5)

set(CMAKE_CXX_STANDARD 11)

add_executable(MS5 PosApp.cpp Item.cpp Bill.cpp Date.cpp Perishable.cpp NonPerishable.cpp PosIO.cpp Utils.cpp main.cpp Error.cpp)
