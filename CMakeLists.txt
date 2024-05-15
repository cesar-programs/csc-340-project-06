cmake_minimum_required(VERSION 3.22)
project(csc-340-project-06)

set(CMAKE_CXX_STANDARD 17)

add_executable(csc-340-project-06 main.cpp
        World.cpp
        World.h
        Organism.cpp
        Organism.h
        Predator.cpp
        Predator.h
        Prey.cpp
        Prey.h)
