cmake_minimum_required(VERSION 2.6)
project(dasAuto)

add_definitions(-std=c++0x -Wall -fexceptions)

get_property(LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS)

if ("${LIB64}" STREQUAL "TRUE")
    set(LIBSUFFIX 64)
else()
    set(LIBSUFFIX "")
endif()

set(INSTALL_LIB_DIR lib${LIBSUFFIX} CACHE PATH "Installation directory for libraries")
mark_as_advanced(INSTALL_LIB_DIR)

# Temporary soultion for building the binary file
include_directories(src/3rdparty/gpio/src)

add_subdirectory(src/3rdparty/gpio)

file(GLOB SRCS "src/app/*.cpp")
file(GLOB HDRS "src/app/*.h")

add_executable(dasAuto ${SRCS} ${HDRS})
 
target_link_libraries(dasAuto BeagleBoneGPIO) 

install(TARGETS dasAuto DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)
