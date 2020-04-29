cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_sources(GodamnLib
    PRIVATE
        Scene.h
        Scene.cpp
        SceneryManager.cpp
        SceneryManager.h
        SceneryException.h
)