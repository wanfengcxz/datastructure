//
// Created by 晚风吹行舟 on 2021/5/2.
//
#include "gtest/gtest.h"
#include "ExpressionEvaluation.cpp"
#include <cmath>

// 判断浮点数是否相等
bool essentiallyEqual(double a, double b, double epsilon) {
    return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}


TEST(parseFormula_letterTest, rightInput){
    ASSERT_STREQ(parseFormula_letter("a*(b+c)-d").c_str(),"abc+*d-");
    ASSERT_STREQ(parseFormula_letter("a+b-a*((c+d)/e-f)+g").c_str(),"ab+acd+e/f-*-g+");
    ASSERT_STREQ(parseFormula_letter("a+b*(c-d)-e/f").c_str(),"abcd-*+ef/-");
}

TEST(ExpressionEvaluationTest, rightInput){
    ASSERT_EQ(essentiallyEqual(ExpressionEvaluation("3*(20+5)+5"), 80.0, 0.0000001), true);
    ASSERT_EQ(essentiallyEqual(ExpressionEvaluation("16+2*30/4"), 31.0, 0.0000001), true);
    ASSERT_EQ(essentiallyEqual(ExpressionEvaluation("2+(3+4)*5"), 37.0, 0.0000001), true);
    ASSERT_EQ(essentiallyEqual(ExpressionEvaluation("5+(2*4)/5+2*(10/2+(2+2)*5)"), 56.6, 0.0000001), true);

//    ASSERT_EQ(ExpressionEvaluation("16+2*30/4"), 31.0);
//    ASSERT_EQ(ExpressionEvaluation("2+(3+4)*5"), 37.0);
//    ASSERT_EQ(ExpressionEvaluation("5+(2*4)/5+2*(10/2+(2+2)*5)"), 56.6);

}

int main() {

    // test parseFormula_digit
//    std::vector<std::string> res = parseFormula_digit("3*(20+5)+5");
//    for (int i = 0;i<res.size();i++){
//        std::cout << res[i] << " ";
//    }
//    std::cout << std::endl;
//    res = parseFormula_digit("16+2*30/4");
//    for (int i = 0;i<res.size();i++){
//        std::cout << res[i] << " ";
//    }
//    std::cout << std::endl;
//    res = parseFormula_digit("2+(3+4)*5");
//    for (int i = 0;i<res.size();i++){
//        std::cout << res[i] << " ";
//    }

    // tes ExpressionEvaluation
//    std::cout << ExpressionEvaluation("3*(20+5)+5") << std::endl;
//    std::cout << ExpressionEvaluation("16+2*30/4") << std::endl;
//    std::cout << ExpressionEvaluation("2+(3+4)*5");

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}