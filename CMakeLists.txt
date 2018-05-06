cmake_minimum_required(VERSION 3.0)
project(clog VERSION 0.7 DESCRIPTION "Asynchronous fast logging library for C")

enable_testing()
file(GLOB_RECURSE clog_HDRS "include/clog/clog.h")
file(GLOB_RECURSE clog_SRCS "src/clog.c")
find_package(Threads REQUIRED)

option(ENABLE_CLOG_COLOR "Enables colors in debugging" ON)

function(build_lib varValue)
#no-op lib
add_library(clog ${varValue} ${clog_SRCS})
#debugging lib
add_library(clogd ${varValue} ${clog_SRCS})
target_compile_definitions(clogd PRIVATE -DENABLE_CLOG)
if(ENABLE_CLOG_COLOR)
target_compile_definitions(clogd PRIVATE -DENABLE_CLOG_COLOR)
endif()
endfunction(build_lib)

if(BUILD_SHARED_LIBS)
	#shared lib
	build_lib(SHARED)
else()
	#static lib
	build_lib(STATIC)
endif()

target_include_directories(clog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(clogd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(clogd ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(clog PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(clogd PROPERTIES VERSION ${PROJECT_VERSION})


install(FILES ${clog_HDRS} DESTINATION include/clog)

install (TARGETS clog
		PUBLIC_HEADER DESTINATION include/clog
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin)

install (TARGETS clogd
		PUBLIC_HEADER DESTINATION include/clog
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
		RUNTIME DESTINATION bin)

add_executable(clog_test_exec test/test.c)
add_executable(clogd_test_exec test/test.c)
target_link_libraries(clog_test_exec clog)
target_link_libraries(clogd_test_exec clogd)

add_test(clog_test ${CMAKE_BINARY_DIR}/clog_test_exec)
add_test(clogd_test ${CMAKE_BINARY_DIR}/clogd_test_exec)
