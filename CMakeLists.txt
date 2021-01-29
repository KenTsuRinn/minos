cmake_minimum_required(VERSION 3.16)
project(minos)

set(CMAKE_CXX_STANDARD 20)
file(COPY data/jin_ping_mei_15.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(minos main.cpp src/utf.cpp inc/inverted_item.h inc/inverted_index.h)
target_include_directories(minos PUBLIC inc)