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

TEST(BracketMatching_3Test, rightinput){
    ASSERT_EQ(BracketMatching_3("[(2+2.54)+2]"),true);
    ASSERT_EQ(BracketMatching_3("(3+2)*5.0+{3+[(2*3)+2]}"), true);
    ASSERT_EQ(BracketMatching_3("(2+3)*3.5-{3-[2+3/(2+2)]}"), true);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}