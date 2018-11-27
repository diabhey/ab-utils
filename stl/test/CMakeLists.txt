cmake_minimum_required (VERSION 3.11)

set(SOURCES_DIR ../src)
set(INCLUDES_DIR ../include)

set(header_impl
   ${INCLUDES_DIR}/Vector.h
   )

set(unittest_files
        VectorTest.cpp
        RunTests.cpp
        )

find_package(GTest REQUIRED)
include_directories(${INCLUDES_DIR} ${GTEST_INCLUDE_DIRS})

add_executable(utilities_test ${unittest_files} ${header_impl})
target_link_libraries(utilities_test ${GTEST_LIBRARIES} pthread )
