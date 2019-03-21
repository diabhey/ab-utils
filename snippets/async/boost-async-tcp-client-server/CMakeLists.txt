project(asio)

cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

add_executable(client src/TcpClient.cpp)
add_executable(server src/TcpServer.cpp)

target_link_libraries(client Threads::Threads)
target_link_libraries(server Threads::Threads)
