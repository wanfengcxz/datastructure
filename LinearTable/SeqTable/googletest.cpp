//
// Created by 晚风吹行舟 on 2021/4/17.
//
#pragma once

#include "SeqTable.cpp"
#include "gtest/gtest.h"


int add(int a, int b) {
    return a + b;
}

TEST(add, zero) {
    EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive_number) {
    EXPECT_EQ(3, add(1, 2));
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}




