set(SOURCE_FILES MirageApp.cpp GameWindow.cpp GLFWimpl/GlfwImplementation.cpp)

set(HEADER_FILES Mirage.h MirageApp.h MirageUtils.h WindowImplementation.h GameWindow.h GLFWimpl/GlfwImplementation.h)

add_library(mirage_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(mirage_lib PRIVATE pch.h)

add_definitions(-DMIRAGE_LIB)

target_link_libraries(mirage_lib glfw)

include_directories(../glfw-3.3.5/include)
include_directories(../Mirage)