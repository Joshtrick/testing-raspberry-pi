set(MY_EXE test_rw_speed)
add_executable(${MY_EXE} ${MY_EXE}.cpp)
target_link_libraries(${MY_EXE} ${PROJECT_NAME})

set(MY_EXE test_tcp_speed_server)
add_executable(${MY_EXE} ${MY_EXE}.cpp)
target_link_libraries(${MY_EXE} ${PROJECT_NAME})

set(MY_EXE test_tcp_speed_client)
add_executable(${MY_EXE} ${MY_EXE}.cpp)
target_link_libraries(${MY_EXE} ${PROJECT_NAME})

set(MY_EXE bin_generator)
add_executable(${MY_EXE} ${MY_EXE}.cpp)
target_link_libraries(${MY_EXE} ${PROJECT_NAME})

set(MY_EXE video)
add_executable(${MY_EXE} ${MY_EXE}.c)
target_link_libraries(${MY_EXE} ${PROJECT_NAME})
