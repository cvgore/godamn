cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_sources(GodamnLib
    PRIVATE
        Container.cpp
        Container.h
        Object.cpp
        Object.h
        Exception.h
        Exception.cpp
)