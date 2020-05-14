cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_sources(GodamnLib
    PRIVATE
        Generator.cpp
        Generator.h
        game_map.h
        game_map.cpp
        IPoint.h
        IPoint.cpp
        res_generator.h
        res_generator.cpp
)