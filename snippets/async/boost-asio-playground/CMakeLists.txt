project(asio-playground)

cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(boost-cmake)
add_executable(app src/main.cpp)

target_link_libraries(app PUBLIC Boost::thread)
