set(SOURCE_FILES MirageApp.cpp)

set(HEADER_FILES Mirage.h MirageApp.h MirageUtils.h)

add_libary(mirage_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(mirage_lib PRIVATE pch.h)