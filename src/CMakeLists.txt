file(GLOB srcs *.cpp *.c)

#Create the libraries
add_library(${PROJECT_NAME} SHARED ${srcs})

#Link libraries
target_link_libraries(${PROJECT_NAME})

#add_subdirectory(../test/)
