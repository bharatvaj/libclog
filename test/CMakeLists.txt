cmake_minimum_required(VERSION 3.8)
project(clog_test)

add_executable(clog_test test.c)
target_link_libraries(clog_test clog)
target_include_directories(clog_test PRIVATE clog)

# todo
add_test(clog_long_msg_test clog_test long_message)
add_test(clog_functions_test clog_test clog_functions)
