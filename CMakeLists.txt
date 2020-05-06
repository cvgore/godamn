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

if(NOT SFML_DIR)
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_LIST_DIR}/lib/" ${CMAKE_PREFIX_PATH})
endif()

add_compile_definitions(APP_NAME="${APP_NAME}" APP_VERSION="${APP_VERSION}")

project(Gra VERSION ${APP_VERSION} LANGUAGES CXX)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

include_directories(lib/SFML)
include_directories(lib/doctest)

add_library(GodamnLib "")

add_subdirectory(Utils)
add_subdirectory(Foundation)
add_subdirectory(Structs)
add_subdirectory(Config)
add_subdirectory(Screen)
add_subdirectory(Scenery)
add_subdirectory(Events)
add_subdirectory(Entities)

add_subdirectory(lib/doctest)
add_subdirectory(tests)

add_executable(Game main.cpp GameState.cpp Engine.cpp)

target_link_libraries(GodamnLib PUBLIC sfml-graphics)
target_link_libraries(Game PUBLIC sfml-graphics PRIVATE GodamnLib)

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Utils")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib")

target_include_directories(Game PUBLIC ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})

# Copy assets
add_custom_command(TARGET Game POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Game>/assets)
