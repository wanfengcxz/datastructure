cmake_minimum_required(VERSION 3.19)
project(datastructure)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(googletest/include googletest)

add_executable(test main.cpp)
target_link_libraries(test gtest gtest_main)


add_executable(seqtabletest ./LinearTable/SeqTable/googletest.cpp)
target_link_libraries(seqtabletest gtest gtest_main)