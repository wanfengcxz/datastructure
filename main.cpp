#include "gtest/gtest.h"
#include <stack>

class stack_test : public ::testing::Test {
protected:
    std::stack<int> teststack;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        teststack.push(1);
        teststack.push(2);
    }

};

int add(int a, int b) {
    return a + b;
}

TEST(add, zero) {
EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive_number) {
EXPECT_EQ(3, add(1, 2));
}

TEST(add, negative_number) {
EXPECT_EQ(-3, add(-1, -2));
}

int main() {
//    int a = 5,b = 1;
//    std::cout << (b=a) << std::endl;
    std::stack<int> s;
    std::cout << s.top() << std::endl;
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


