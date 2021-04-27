//
// Created by 晚风吹行舟 on 2021/4/27.
//
#include "gtest/gtest.h"
#include "ShareStack.h"
#include "ShareStack.cpp"

class ShareStackTest : public ::testing::Test {

protected:
    ShareStack<int> sharedStack;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

};

TEST_F(ShareStackTest, stack) {
    ASSERT_EQ(sharedStack.empty(1), true);
    ASSERT_EQ(sharedStack.pop(2), false);
    sharedStack.push(1, 1);
    ASSERT_EQ(sharedStack.empty(1), false);
    ASSERT_EQ(sharedStack.empty(2), true);
    sharedStack.push(2, 1);
    sharedStack.push(1, 2);
    sharedStack.push(2, 2);
    ASSERT_EQ(sharedStack.push(3, 2), true);
    ASSERT_EQ(sharedStack.push(4,2),false);
    int e = 3;
    ASSERT_EQ(sharedStack.top(e, 1),true);
    ASSERT_EQ(e,2);
    ASSERT_EQ(sharedStack.top(e, 2), true);
    ASSERT_EQ(e, 3);
    ASSERT_EQ(sharedStack.pop(2), true);
    ASSERT_EQ(sharedStack.top(e,2),true);
    ASSERT_EQ(e, 2);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

