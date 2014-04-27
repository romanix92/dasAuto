cmake_minimum_required(VERSION 2.6)
project(dasAuto)

add_definitions(-std=c++0x -Wall -fexceptions)

set(GLOBAL_INCLUDE_DIRS "" CACHE INTERNAL "")

add_subdirectory(src/3rdparty/)

message(STATUS "Including directories: ${GLOBAL_INCLUDE_DIRS}")

include_directories(
  ${GLOBAL_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
)

file(GLOB SRCS "src/app/*.cpp")
file(GLOB HDRS "src/app/*.h")

add_executable(dasAuto ${SRCS} ${HDRS})
 
target_link_libraries(dasAuto BeagleBoneGPIO) 

install(TARGETS dasAuto DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)
