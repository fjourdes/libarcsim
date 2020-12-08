cmake_minimum_required(VERSION 3.10)
project(json)

set(HEADERS
    include/json/autolink.h
    include/json/config.h
    include/json/features.h
    include/json/forwards.h
    include/json/json.h
    include/json/reader.h
    include/json/value.h
    include/json/writer.h

    src/lib_json/json_batchallocator.h
)

set(INLINES
    src/lib_json/json_internalarray.inl
    src/lib_json/json_internalmap.inl
    src/lib_json/json_valueiterator.inl

)

set(SOURCES
    src/lib_json/json_reader.cpp
    src/lib_json/json_value.cpp
    src/lib_json/json_writer.cpp
)

set(CMAKE_DEBUG_POSTFIX "d")

add_library(json STATIC
    ${HEADERS}
    ${INLINES}
    ${SOURCES}
)

target_compile_options(json PRIVATE -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)

target_include_directories(json PUBLIC 
                           $<INSTALL_INTERFACE:include>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> )

install( FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/json)
