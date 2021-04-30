//
// Created by 晚风吹行舟 on 2021/4/28.
//
#include "gtest/gtest.h"
#include "LinkedQueue.h"
#include "LinkedQueue.cpp"

class LinkedQueueTest : public ::testing::Test {
protected:
    LinkedQueue linkedQueue;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        linkedQueue.push(1);
        linkedQueue.push(2);
        linkedQueue.push(3);
    }

};

TEST_F(LinkedQueueTest, queue){
    int e = 0;
    ASSERT_EQ(linkedQueue.size(), 3);
    ASSERT_EQ(linkedQueue.empty(), false);
    ASSERT_EQ(linkedQueue.push(4), true);
    ASSERT_EQ(linkedQueue.front(e), true);
    ASSERT_EQ(e,1);
    ASSERT_EQ(linkedQueue.back(e), true);
    ASSERT_EQ(e,4);
    ASSERT_EQ(linkedQueue.push(5), true);
    ASSERT_EQ(linkedQueue.push(6), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.push(6), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), true);
    ASSERT_EQ(linkedQueue.pop(), false);
    ASSERT_EQ(linkedQueue.empty(), true);
    ASSERT_EQ(linkedQueue.front(e), false);
    ASSERT_EQ(linkedQueue.back(e), false);

}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
