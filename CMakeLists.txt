cmake_minimum_required(VERSION 3.0)
project(clog VERSION 0.5 DESCRIPTION "Asynchronous fast logging library for C")
file(GLOB_RECURSE clog_HDRS "include/*.h")
file(GLOB_RECURSE clog_SRCS "src/*.c")

add_library(clog SHARED ${clog_HDRS} ${clog_SRCS})
set_target_properties(clog PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(clog PROPERTIES SOVERSION 1)
set_target_properties(clog PROPERTIES PUBLIC_HEADER ${clog_HDRS})

target_include_directories(clog PUBLIC include)
target_include_directories(clog PUBLIC src)

include(GNUInstallDirs)

install(TARGETS clog 
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/clog)
