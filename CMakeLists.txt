cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(APP_NAME godamn)
set(APP_VERSION 0.1)

add_compile_definitions(APP_NAME="${APP_NAME}" APP_VERSION="${APP_VERSION}")

project (Gra VERSION ${APP_VERSION} LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_subdirectory(Utils)

add_executable(Game main.cpp GameState.cpp TiledMap.cpp Player.cpp)

target_link_libraries(Game sfml-graphics Utils)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Utils")

target_include_directories(Game PUBLIC ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})

file(COPY ./assets DESTINATION ${PROJECT_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES})
