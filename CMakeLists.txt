cmake_minimum_required(VERSION 3.19)
project(datastructure)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(googletest/include googletest)

# test
add_executable(test main.cpp)
target_link_libraries(test gtest gtest_main)

# SeqTable
add_executable(SeqTableTest ./LinearTable/SeqTable/googletest.cpp)
target_link_libraries(SeqTableTest gtest gtest_main)

# LinkedList
## SingleLinkedList
add_executable(SingleLinkedListTest ./LinearTable/LinkedList/SingleLinkedList/SingleLinkedList_test.cpp)
target_link_libraries(SingleLinkedListTest gtest gtest_main)

## StaticLinkedList
add_executable(StaticLinkedListTest ./LinearTable/LinkedList/StaticLinkedList/StaticLinkedList_test.cpp)
target_link_libraries(StaticLinkedListTest gtest gtest_main)


