cmake_minimum_required(VERSION 2.8)

project(my_project)

include_directories(${CMAKE_SOURCE_DIR}/inc/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)

#Add external include directories
include_directories(
  /usr/local/include/
  /opt/vc/include/
  /opt/vc/src/hello_pi/
  /opt/vc/src/hello_pi/libs/ilclient/
  )

#Link external libraries diectories
link_directories(
  /opt/vc/lib/
  )

#Link external libraries
link_libraries(
  -lpthread
  -lbcm_host
  -lopenmaxil
  /opt/vc/src/hello_pi/libs/ilclient/libilclient.a
  /opt/vc/src/hello_pi/libs/vgfont/libvgfont.a
  )

#Add sub-directories of the project
add_subdirectory(src/)
add_subdirectory(test/)
