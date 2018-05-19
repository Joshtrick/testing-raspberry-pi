add_executable(test_rw_speed test_rw_speed.cpp)
target_link_libraries(test_rw_speed ${PROJECT_NAME})

add_executable(test_tcp_speed_server test_tcp_speed_server.cpp)
target_link_libraries(test_tcp_speed_server ${PROJECT_NAME})

add_executable(test_tcp_speed_client test_tcp_speed_client.cpp)
target_link_libraries(test_tcp_speed_client ${PROJECT_NAME})
