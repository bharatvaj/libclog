cmake_minimum_required(VERSION 3.0)
project(clog VERSION 0.8 DESCRIPTION "Asynchronous fast logging library for C")

enable_testing()
file(GLOB clog_HDRS "include/clog/clog.h")
file(GLOB clog_SRCS "src/clog.c")
find_package(Threads REQUIRED)

add_library(clog ${clog_SRCS})

target_include_directories(clog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(clog ${CMAKE_THREAD_LIBS_INIT})
set_target_properties(clog PROPERTIES VERSION ${PROJECT_VERSION})

install(FILES clog-config.cmake DESTINATION lib/cmake/clog)
install(FILES ${clog_HDRS} DESTINATION include/clog)
install (TARGETS clog
		PUBLIC_HEADER DESTINATION include/clog
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin)

add_executable(clog_test_exec test/test.c)
target_include_directories(clog_test_exec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(clog_test_exec clog)

add_test(clog_test ${CMAKE_BINARY_DIR}/clog_test_exec)

