cmake_minimum_required(VERSION 3.10)
project(alglib)

set(HEADERS
    cpp/src/alglibinternal.h
    cpp/src/alglibmisc.h
    cpp/src/ap.h
    cpp/src/dataanalysis.h
    cpp/src/diffequations.h
    cpp/src/fasttransforms.h
    cpp/src/integration.h
    cpp/src/interpolation.h
    cpp/src/linalg.h
    cpp/src/optimization.h
    cpp/src/solvers.h
    cpp/src/specialfunctions.h
    cpp/src/statistics.h
    cpp/src/stdafx.h
)

set(SOURCES
    cpp/src/alglibinternal.cpp
    cpp/src/alglibmisc.cpp
    cpp/src/ap.cpp
    cpp/src/dataanalysis.cpp
    cpp/src/diffequations.cpp
    cpp/src/fasttransforms.cpp
    cpp/src/integration.cpp
    cpp/src/interpolation.cpp
    cpp/src/linalg.cpp
    cpp/src/optimization.cpp
    cpp/src/solvers.cpp
    cpp/src/specialfunctions.cpp
    cpp/src/statistics.cpp
)


set(CMAKE_DEBUG_POSTFIX "d")

add_library(alglib STATIC
    ${HEADERS}
    ${SOURCES}
)

target_compile_options(alglib PRIVATE -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)


target_include_directories(alglib PUBLIC 
                           $<INSTALL_INTERFACE:include>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cpp/src> )


install( FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/alglib)
