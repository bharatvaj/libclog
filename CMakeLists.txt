cmake_minimum_required(VERSION 3.0)
project(clog VERSION 0.6 DESCRIPTION "Asynchronous fast logging library for C")
file(GLOB_RECURSE clog_HDRS "include/clog/clog.h")
file(GLOB_RECURSE clog_SRCS "src/clog.c")
find_package(Threads REQUIRED)

option(ENABLE_CLOG_COLOR "Enables colors in debugging" ON)

#no-op lib
add_library(clog SHARED ${clog_SRCS})

#debugging lib
add_library(clogd SHARED ${clog_SRCS})
target_compile_definitions(clogd PRIVATE -DENABLE_CLOG)
if(ENABLE_CLOG_COLOR)
	target_compile_definitions(clogd PRIVATE -DENABLE_CLOG_COLOR)
endif()	

target_include_directories(clog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(clogd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(clogd ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(clog PROPERTIES VERSION ${PROJECT_VERSION})

set_target_properties(clogd PROPERTIES VERSION ${PROJECT_VERSION})


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