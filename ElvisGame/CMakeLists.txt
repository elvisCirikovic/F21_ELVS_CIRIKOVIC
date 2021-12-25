add_executable(elvis_game main.cpp ElvisGameApp.h ElvisGameApp.cpp Unit.h Unit.cpp)

target_link_libraries(elvis_game mirage_lib)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.. PROPERTY VS_STARTUP_PROJECT elvis_game)

include_directories(../Mirage)

file(COPY Assets DESTINATION ../ElvisGame)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)