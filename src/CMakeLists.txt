#No need to change this CMakeLists in most cases.
file(GLOB SRC  *.c *.cpp)

#Create the libraries
add_library(${PROJECT_NAME} SHARED ${SRC})
