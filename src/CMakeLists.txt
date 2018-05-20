#No need to change this CMakeLists in most cases.
file(GLOB srcs *.cpp *.c)

#Create the libraries
add_library(${PROJECT_NAME} SHARED ${srcs})
