//
// Created by 晚风吹行舟 on 2021/4/27.
//
#include "gtest/gtest.h"
#include "LinkedStack.h"
#include "LinkedStack.cpp"

class LinkedStackTest : public ::testing::Test {
protected:
    LinkedStack<int> linkedStack;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        linkedStack.push(1);
        linkedStack.push(2);
    }

};


TEST_F(LinkedStackTest, stack) {
    int e = 3;
    EXPECT_EQ(linkedStack.top(e),true);
    ASSERT_EQ(e,2);
    ASSERT_EQ(linkedStack.pop(),true);
    ASSERT_EQ(linkedStack.pop(),true);
    ASSERT_EQ(linkedStack.pop(),false);
    ASSERT_EQ(linkedStack.empty(),true);
    ASSERT_EQ(linkedStack.push(5),true);
    ASSERT_EQ(linkedStack.empty(),false);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}