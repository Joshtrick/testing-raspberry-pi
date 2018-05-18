file(GLOB srcs *.cpp *.c)

add_library(${PROJECT_NAME} SHARED ${srcs})

target_link_libraries(${PROJECT_NAME})

#add_subdirectory(../test/)
