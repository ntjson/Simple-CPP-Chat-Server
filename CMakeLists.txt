cmake_minimum_required(VERSION 4.0)
project(socket)

set(CMAKE_CXX_STANDARD 20)

add_executable(server server.cpp)
target_link_libraries(server ws2_32)

add_executable(client client.cpp)
target_link_libraries(client ws2_32)