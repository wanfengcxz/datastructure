//
// Created by 晚风吹行舟 on 2021/5/5.
//
#include "gtest/gtest.h"
#include "kmp.cpp"


TEST(KMPTEST, rightInput) {
    ASSERT_EQ(kmp("ababcabcacbab","abcac"), 5);
    ASSERT_EQ(kmp("aaacaaab","aaab"),4);
    ASSERT_EQ(kmp("1212312313212","12313"),5);
}

TEST(KMPTEST, wrongInput){

}

int main(){
//    int n = 9;
//    char *pattern = "ABABCABAA";
//    int *prefix = new int[n];
//    prefix_table(pattern,prefix,n);
//
//    for (int i = 0;i<n;i++){
//        cout << prefix[i] << endl;
//    }

    cout <<  kmp("ababcabcacbab","abcac");
    cout << kmp("aaacaaab","aaab") << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}