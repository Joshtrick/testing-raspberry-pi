cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME my_project)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(src/)
add_subdirectory(test/)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#link other libraries
#include headers directories
include_directories(
  /usr/local/include/
  )
#link libraries
link_directories(
  /usr/lib/
  /usr/local/lib/
  )
