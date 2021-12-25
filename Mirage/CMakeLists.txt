set(SOURCE_FILES MirageApp.cpp GameWindow.cpp GLFWimpl/GlfwImplementation.cpp Renderer.cpp Shader.cpp Sprite.cpp Events.cpp OpenGLimpl/OpenGLRenderer.cpp OpenGLimpl/OpenGLShader.cpp OpenGLimpl/OpenGLSprite.cpp)

set(HEADER_FILES Mirage.h MirageApp.h MirageUtils.h WindowImplementation.h GameWindow.h GLFWimpl/GlfwImplementation.h KeyCodes.h Renderer.h RendererImplementation.h Shader.h Events.h ShaderImplementation.h Sprite.h SpriteImplementation.h OpenGLimpl/OpenGLRenderer.h OpenGLimpl/OpenGLShader.h OpenGLimpl/OpenGLSprite.h)

add_library(mirage_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(mirage_lib PRIVATE pch.h)

add_definitions(-DMIRAGE_LIB)

target_link_libraries(mirage_lib glfw glad stbi)


include_directories(../glfw-3.3.5/include)
include_directories(../Mirage)
include_directories(../glad/include)
include_directories(../stbi)