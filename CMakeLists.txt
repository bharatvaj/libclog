cmake_minimum_required(VERSION 3.0)
project(clog VERSION 0.5 DESCRIPTION "Asynchronous fast logging library for C" LANGUAGES C)
file(GLOB_RECURSE clog_HDRS "include/*.h")
file(GLOB_RECURSE clog_SRCS "src/*.c")

option(ENABLE_CLOG_COLOR "Enables colors in debugging" ON)

if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE "Debug")
endif()

#build options
if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
option(ENABLE_CLOG
	"Enable debugging" OFF)
else()
	option(ENABLE_CLOG "Enable debugging" ON)
endif()
if(ENABLE_CLOG)
	add_definitions(-DENABLE_CLOG)
	if(ENABLE_CLOG_COLOR)
		add_definitions(-DENABLE_CLOG_COLOR)
	endif()
endif()

add_library(clog STATIC ${clog_HDRS} ${clog_SRCS})
set_target_properties(clog PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(clog PROPERTIES SOVERSION 1)
set_target_properties(clog PROPERTIES PUBLIC_HEADER ${clog_HDRS})

target_include_directories(clog PUBLIC include)
target_include_directories(clog PUBLIC src)

