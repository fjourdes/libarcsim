cmake_minimum_required(VERSION 3.10)
project(ArcSim)


option(ARCSIM_WITH_PNG OFF)
option(ARCSIM_WITH_BOOST OFF)

if(ARCSIM_WITH_PNG)
    find_package(PNG REQUIRED)
endif()

if(ARCSIM_WITH_BOOST)
    find_package(Boost REQUIRED COMPONENTS system filesystem)
endif()

find_package(Eigen3 REQUIRED)

add_subdirectory(deps/alglib)
add_subdirectory(deps/jsoncpp)


add_library(ArcSim::alglib ALIAS alglib)
add_library(AcrSim::json ALIAS json)


# include_directories(src include deps/alglib/cpp/src deps/jsoncpp/include ${PNG_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

file(GLOB ARCSIM_SOURCES src/*.cpp)
file(GLOB ARCSIM_HEADERS include/*.hpp)

configure_file(include/arcsim.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/arcim/arcsim.hpp @ONLY)

add_library(arcsim ${ARCSIM_SOURCES} ${ARCSIM_HEADERS})
target_link_libraries(arcsim PUBLIC alglib json Eigen3::Eigen)
target_include_directories(arcsim PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)


add_library(ArcSim::arcsim ALIAS arcsim)

if(ARCSIM_WITH_PNG)
    target_link_libraries(arcsim PUBLIC PNG::PNG ) 
endif()

if(ARCSIM_WITH_BOOST)
    target_link_libraries(acrsim PUBLIC Boost::system Boost::filesystem Boost::disable_autolinking Boost::dynamic_linking)
endif()

include(GNUInstallDirs)

install(TARGETS alglib json arcsim
        EXPORT ArcSimTargets
        INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        RUNTIME DESTINATION  "${CMAKE_INSTALL_BINDIR}"
        LIBRARY DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION  "${CMAKE_INSTALL_LIBDIR}"
)

install(FILES ${ARCSIM_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/arcsim )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/arcim/arcsim.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/arcsim)

include(CMakePackageConfigHelpers)

configure_package_config_file(ArcSimConfig.cmake.in
    ${CMAKE_BINARY_DIR}/arcsim/ArcSimConfig.cmake
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArcSim"
)


install(FILES ${CMAKE_BINARY_DIR}/arcsim/ArcSimConfig.cmake
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArcSim")

install( EXPORT ArcSimTargets
        NAMESPACE "ArcSim::"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/ArcSim")
