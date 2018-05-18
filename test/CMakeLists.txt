add_executable(test_rw_speed test_rw_speed.cpp)
target_link_libraries(test_rw_speed ${PROJECT_NAME})

add_executable(test_tcp_speed test_tcp_speed.cpp)
target_link_libraries(test_tcp_speed ${PROJECT_NAME})
