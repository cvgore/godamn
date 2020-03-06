cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project (Gra VERSION 0.1 LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_subdirectory(Utils)

add_executable(Game main.cpp main.h)

target_link_libraries(Game sfml-graphics sfml-audio Utils)

target_include_directories(Game PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/Utils)
