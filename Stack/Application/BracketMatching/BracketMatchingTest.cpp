//
// Created by 晚风吹行舟 on 2021/5/1.
//
#include "BracketMatching.cpp"
#include "gtest/gtest.h"

TEST(BracketMatchingTest, rightInput){
    ASSERT_EQ(BracketMatching("[]()[]()"),true);
    ASSERT_EQ(BracketMatching("([([])([[]])]())"),true);
    ASSERT_EQ(BracketMatching("([[()]()]([()]))([]([]))"),true);

}

TEST(BracketMatchingTest, wrongInput){
    ASSERT_EQ(BracketMatching("[]([])[])"),false);
    ASSERT_EQ(BracketMatching("[(])"),false);
    ASSERT_EQ(BracketMatching("[([]([()])_)]"),false);
    ASSERT_EQ(BracketMatching("(1(2[]3)a)sd"),false);
    ASSERT_EQ(BracketMatching("[[()(])]"),false);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}