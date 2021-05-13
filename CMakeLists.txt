cmake_minimum_required(VERSION 3.19)
project(datastructure)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
include_directories(googletest/include googletest)

# demo
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
add_executable(SqStackTest Stack/SeqStack/SqStackTest.cpp)
target_link_libraries(SqStackTest gtest gtest_main)

## LinkedStack
add_executable(LinkedStackTest Stack/LinkedStack/LinkedStackTest.cpp)
target_link_libraries(LinkedStackTest gtest gtest_main)

### Problems
add_executable(StackQueueProblemTest Stack/Problem/ProblemTest.cpp)
target_link_libraries(StackQueueProblemTest gtest gtest_main)

## application
### 括号匹配
add_executable(BracketMatchingTest Stack/Application/BracketMatching/BracketMatchingTest.cpp)
target_link_libraries(BracketMatchingTest gtest gtest_main)

### 表达式求值
add_executable(ExpressionEvaluationTest Stack/Application/ExpressionEvaluation/ExpressionEvaluationTest.cpp)
target_link_libraries(ExpressionEvaluationTest gtest gtest_main)

## ShareStack
add_executable(ShareStackTest Stack/ShareStack/ShareStackTest.cpp)
target_link_libraries(ShareStackTest gtest gtest_main)

# Queue
## CircularQueue
add_executable(CircularQueueTest Queue/CircularQueue/CircularQueueTest.cpp)
target_link_libraries(CircularQueueTest gtest gtest_main)

## LinkedQueue
add_executable(LinkedQueueTest Queue/LinkedQueue/LinkedQueueTest.cpp)
target_link_libraries(LinkedQueueTest gtest gtest_main)

# String
## 堆分配存储
add_executable(StringTest String/String/StringTest.cpp)
target_link_libraries(StringTest gtest gtest_main)


## KMP
add_executable(KMPTest String/KMP/kmpTest.cpp)
target_link_libraries(KMPTest gtest gtest_main)


# Tree
## BinaryTree
add_executable(BinaryTreeTest Tree/BinaryTree/BinaryTreeTest.cpp)
target_link_libraries(BinaryTreeTest gtest gtest_main)

## ThreadBinaryTree
add_executable(ThreadBinaryTreeTest Tree/ThreadBinaryTree/ThreadBinaryTreeTest.cpp)
target_link_libraries(ThreadBinaryTreeTest gtest gtest_main)


