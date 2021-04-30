//
// Created by 晚风吹行舟 on 2021/4/27.
//
#include "gtest/gtest.h"
#include "CircularQueue.h"
#include "CircularQueue.cpp"


class CircularQueueTest : public ::testing::Test {
protected:
    CircularQueue<int> circularQueue;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        circularQueue.push(1);
        circularQueue.push(2);
        circularQueue.push(3);
    }

};

TEST_F(CircularQueueTest, queue) {
    int e = 0;
    ASSERT_EQ(circularQueue.size(), 3);
    ASSERT_EQ(circularQueue.empty(), false);
    ASSERT_EQ(circularQueue.push(4), true);
    ASSERT_EQ(circularQueue.front(e), true);
    ASSERT_EQ(e, 1);
    ASSERT_EQ(circularQueue.back(e), true);
    ASSERT_EQ(e, 4);
    ASSERT_EQ(circularQueue.push(5), true);
    ASSERT_EQ(circularQueue.push(6), false);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.push(6), true);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.pop(), true);
    ASSERT_EQ(circularQueue.pop(), false);
    ASSERT_EQ(circularQueue.empty(), true);
    ASSERT_EQ(circularQueue.front(e), false);
    ASSERT_EQ(circularQueue.back(e), false);

}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}



