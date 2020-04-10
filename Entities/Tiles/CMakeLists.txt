cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_sources(GodamnLib
    PRIVATE
        Tile.cpp
        Tile.h
        TiledMap.cpp
        TiledMap.h
        TileEnum.h
)