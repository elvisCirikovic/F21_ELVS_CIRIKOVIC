cmake_minimum_required(VERSION 3.18)

project(elvis_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DMIRAGE_WINDOWS)
elseif(APPLE)
	add_definitions(-DMIRAGE_MAC)
elseif(UNIX)
	add_definitions(-DMIRAGE_LINUX)
endif()


add_subdirectory(ElvisGame)
add_subdirectory(Mirage)
add_subdirectory(glfw-3.3.5)