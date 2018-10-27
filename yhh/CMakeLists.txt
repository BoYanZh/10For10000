cmake_minimum_required(VERSION 2.7)


set(CMAKE_CXX_STANDARD 14)

add_executable(yhh main.cpp)
target_link_libraries(yhh input_parser)

