#Cmake and bake
cmake_minimum_required(VERSION 3.11)
#Sets PROJECT_NAME, PROJECT_SOURCE_DIR and PROJECT_BINARY_DIR
project(PgnLib)

set( TARGET_NAME PgnLib)

#Let's force some rules, shall we?
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror" )

set( TOP ${PROJECT_SOURCE_DIR} )
set( SRC ${TOP}/src )
set( INCLUDE_DIR ${TOP}/include )
set( LIB ${TOP}/lib )
set( DATA ${TOP}/data)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#Project specifics
set( SRCS
    ${SRC}/main.cpp
    ${SRC}/PgnExtractor.cpp
    ${SRC}/PgnValidator.cpp
    ${SRC}/PgnDisplay.cpp
    )

include_directories(${INCLUDE_DIR} ${DATA})
add_executable(${TARGET_NAME} ${SRCS})
