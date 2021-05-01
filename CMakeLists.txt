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

## problems
add_executable(SingleLinkedListExerciseTest LinearTable/LinkedList/SingleLinkedList/problem_test.cpp)
target_link_libraries(SingleLinkedListExerciseTest gtest gtest_main)

## StaticLinkedList_vacant
add_executable(StaticLinkedListTest LinearTable/LinkedList/StaticLinkedList_vacant/StaticLinkedList_test.cpp)
target_link_libraries(StaticLinkedListTest gtest gtest_main)

# Stack
## SqStack
add_executable(SqStack Stack/SeqStack/SqStack_test.cpp)
target_link_libraries(SqStack gtest gtest_main)

## LinkedStack
add_executable(LinkedStack Stack/LinkedStack/LinkedStack_test.cpp)
target_link_libraries(LinkedStack gtest gtest_main)

## problems
add_executable(LinkedStackProblemTest Stack/LinkedStack/problem_test.cpp)
target_link_libraries(LinkedStackProblemTest gtest gtest_main)

## ShareStack
add_executable(ShareStack Stack/ShareStack/ShareStack_test.cpp)
target_link_libraries(ShareStack gtest gtest_main)

# Queue
## CircularQueue
add_executable(CircularQueue Queue/CircularQueue/CircularQueue_test.cpp)
target_link_libraries(CircularQueue gtest gtest_main)

## LinkedQueue
add_executable(LinkedQueue Queue/LinkedQueue/LinkedQueue_test.cpp)
target_link_libraries(LinkedQueue gtest gtest_main)


