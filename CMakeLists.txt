cmake_minimum_required(VERSION 3.16)
project(minos)

set(CMAKE_CXX_STANDARD 20)
file(GLOB DATA_FILES "./data/jin_ping_mei_*.txt")
file(COPY ${DATA_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)
add_executable(minos main.cpp src/utf.cpp inc/inverted_item.h inc/ContentIterator.h src/ContentIterator.cpp inc/ContentReader.h src/ContentReader.cpp)
target_include_directories(minos PUBLIC inc)