cmake_minimum_required (VERSION 3.13)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})
add_executable (tests tests.cpp)
target_link_libraries(tests PRIVATE doctest PRIVATE GodamnLib)