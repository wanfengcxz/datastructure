//
// Created by 晚风吹行舟 on 2021/4/21.
//
#include "gtest/gtest.h"
#include "SqStack.h"
#include "SqStack.cpp"


class SqStackTest : public ::testing::Test {
protected:
    SqStack sqStack;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        sqStack.push(1);
        sqStack.push(2);
    }

};


TEST_F(SqStackTest, stack) {
    T e = 3;
    ASSERT_EQ(sqStack.top(e),true);
    ASSERT_EQ(e,2);
    ASSERT_EQ(sqStack.pop(),true);
    ASSERT_EQ(sqStack.pop(),true);
    ASSERT_EQ(sqStack.pop(),false);
    ASSERT_EQ(sqStack.empty(),true);
    ASSERT_EQ(sqStack.push(5),true);
    ASSERT_EQ(sqStack.empty(),false);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
