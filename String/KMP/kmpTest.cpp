//
// Created by 晚风吹行舟 on 2021/5/5.
//
#include "gtest/gtest.h"
#include "kmp.cpp"


TEST(KMPTEST, rightInput) {
    ASSERT_EQ(kmp("ababcabcacbab", "abcac"), 5);
    ASSERT_EQ(kmp("aaacaaab", "aaab"), 4);
    ASSERT_EQ(kmp("1212312313212", "12313"), 5);
    ASSERT_EQ(kmp("1233234131431", "23"), 1);
}

TEST(KMPTEST, wrongInput) {
    ASSERT_EQ(kmp("ababcabaab","acb"),-1);
}

int main() {
//    int n = 4;
//    char *pattern = "aaab";
//    int *prefix = new int[n];
//    prefix_table(pattern,prefix,n);
//
//    for (int i = 0;i<n;i++){
//        cout << prefix[i] << endl;
//    }

//    cout << kmp("ababcabcacbab", "abcac") << endl;
//    cout << kmp("aaacaaab", "aaab") << endl;
//    cout << kmp("ababa", "ba") << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}