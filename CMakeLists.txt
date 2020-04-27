cmake_minimum_required (VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(APP_NAME godamn)
set(APP_VERSION 0.1)

if(_DEBUG)
	add_compile_definitions(_CRTDBG_MAP_ALLOC=1)
	add_compile_definitions(__new=new\(_NORMAL_BLOCK,__FILE__,__LINE__\))
else()
	add_compile_definitions(__new=new)
endif()

add_compile_definitions(APP_NAME="${APP_NAME}" APP_VERSION="${APP_VERSION}")

project (Gra VERSION ${APP_VERSION} LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_library(GodamnLib "")

add_subdirectory(Utils)
add_subdirectory(Foundation)
add_subdirectory(Config)
add_subdirectory(Events)
add_subdirectory(Structs)
add_subdirectory(Entities)

add_subdirectory(includes/doctest)

add_subdirectory(tests)

add_executable(Game main.cpp GameState.cpp Engine.cpp "Entities/Tiles/Buildings/LoggingCamp.cpp")

target_link_libraries(GodamnLib PUBLIC sfml-graphics)
target_link_libraries(Game PUBLIC sfml-graphics PRIVATE GodamnLib)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Utils")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/includes")

target_include_directories(Game PUBLIC ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})

file(COPY ./assets DESTINATION ${PROJECT_BINARY_DIR}/${CMAKE_CONFIGURATION_TYPES} REGEX [^.afdesign]$)
