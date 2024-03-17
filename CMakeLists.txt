cmake_minimum_required(VERSION 3.27)
project(Coursework_C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Coursework_C__ main.cpp
        Item.cpp
        Room.cpp
        Player.cpp
        Character.cpp
        Area.hpp
        Area.cpp
        CommandInterpreter.hpp
        CommandInterpreter.cpp
        Monster.cpp)
