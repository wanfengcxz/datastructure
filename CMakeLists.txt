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
add_executable(SingleLinkedListTest LinearTable/LinkedList/SingleLinkedList/SingleLinkedListTest.cpp)
target_link_libraries(SingleLinkedListTest gtest gtest_main)

### problems
add_executable(SingleLinkedListExerciseTest LinearTable/LinkedList/SingleLinkedList/problemTest.cpp)
target_link_libraries(SingleLinkedListExerciseTest gtest gtest_main)

## StaticLinkedList_vacant
add_executable(StaticLinkedListTest LinearTable/LinkedList/StaticLinkedList_vacant/StaticLinkedList_test.cpp)
target_link_libraries(StaticLinkedListTest gtest gtest_main)

# Stack
## SqStack
add_executable(SqStack Stack/SeqStack/SqStackTest.cpp)
target_link_libraries(SqStack gtest gtest_main)

## LinkedStack
add_executable(LinkedStack Stack/LinkedStack/LinkedStackTest.cpp)
target_link_libraries(LinkedStack gtest gtest_main)

### problems
add_executable(LinkedStackProblemTest Stack/LinkedStack/problemTest.cpp)
target_link_libraries(LinkedStackProblemTest gtest gtest_main)

## application
add_executable(BracketMatching Stack/Application/BracketMatching/BracketMatchingTest.cpp)
target_link_libraries(BracketMatching gtest gtest_main)

## ShareStack
add_executable(ShareStack Stack/ShareStack/ShareStackTest.cpp)
target_link_libraries(ShareStack gtest gtest_main)

# Queue
## CircularQueue
add_executable(CircularQueue Queue/CircularQueue/CircularQueueTest.cpp)
target_link_libraries(CircularQueue gtest gtest_main)

## LinkedQueue
add_executable(LinkedQueue Queue/LinkedQueue/LinkedQueueTest.cpp)
target_link_libraries(LinkedQueue gtest gtest_main)


