//
// Created by 晚风吹行舟 on 2021/5/6.
//
#include "gtest/gtest.h"
#include "String.h"
#include "String.cpp"
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;


TEST(StringTest, fun) {

    // constructor
    String str1;
    String str2("123");
    String str3("123456789123456789");
    // 调用拷贝构造函数
    String str4(str2);

    // size capacity
    ASSERT_EQ(str1.size(), 0);
    ASSERT_EQ(str1.capacity(), String::block());
    ASSERT_EQ(str2.size(), 3);
    ASSERT_EQ(str2.capacity(), String::block());
    ASSERT_STREQ(str2.c_str(), "123");
    ASSERT_EQ(str3.size(), 18);
    ASSERT_EQ(str3.capacity(), String::block() * 2);
    ASSERT_STREQ(str3.c_str(), "123456789123456789");

    // = + +=
    str1 += "1";
    ASSERT_EQ(str1.size(), 1);
    ASSERT_EQ(str1.capacity(), String::block());
    str2 = str3 + str4;
    ASSERT_EQ(str2.size(), 21);
    ASSERT_EQ(str2.capacity(), String::block() * 2);
    ASSERT_EQ(str3.size(), 18);
    ASSERT_EQ(str3.capacity(), String::block() * 2);
    str4 += str1;
    ASSERT_EQ(str4.size(), 4);
    ASSERT_EQ(str4.capacity(), String::block());

    // ==
    String str6("1231");
    String str7(str4);
    ASSERT_EQ(str6.size() == str4.size(), true);
    ASSERT_EQ(str6 == str4, true);
    ASSERT_EQ(str7 == str4, true);
    ASSERT_EQ(str3 == str1, false);

    // []
    ASSERT_EQ(str3[1],'2');
    ASSERT_EQ(str3[3],'4');

    // substr
}

int main() {

    // 15 31 47
//    string str = "111111111111111111111111111111111111111111111111";
//    cout << str.size() << endl;
//    cout << str.capacity() << endl;
//    cout << str.substr(1, 5).capacity() << endl;
//
//    string str1 = "123";
//    cout << str1.capacity() << endl;
//    str1 += "111111111111111111111111111111111111";
//    cout << str1.capacity() << endl;

//    String s1;
//    String s2 = s1;
//    s1 = s1 + s2;
    /*
     * console will print:
     * copy constructor is called
     * copy constructor is called
     * = function is called
     */

//    String str;
//    cin >> str;
//    cout << str << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();

    return 0;
}