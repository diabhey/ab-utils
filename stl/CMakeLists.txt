project(stl)

cmake_minimum_required (VERSION 3.11)

add_definitions(-std=c++17)

#set(CXX_FLAGS "-Wall")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++-7")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++-6.0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE_DIR ${SRC}/include)

include_directories(${INCLUDE_DIR})

# Test
add_subdirectory(test)
