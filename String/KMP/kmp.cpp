//
// Created by 晚风吹行舟 on 2021/5/5.
//
#include <iostream>

using namespace std;

/**
 * 获取前缀表
 * @param pattern 子串
 * @param prefix 前缀表
 * @param n 串长
 */
void prefix_table(char pattern[], int prefix[], int n) {
    prefix[0] = 0;
    int len = 0;
    int index = 1;
    while (index < n) {
        if (pattern[index] == pattern[prefix[len]]) {
            prefix[index] = prefix[len] + 1;
            len = index++;
        } else {
            if (prefix[len] > 0) {
                len = prefix[len - 1];
            } else {
                len = index;
                prefix[index++] = 0;
            }
        }
    }
    // i
    for (int j = n - 1; j > 0; j--) {
        prefix[j] = prefix[j - 1];
    }
    prefix[0] = -1;
}

/**
 * kmp字符串匹配算法
 * @param text 主串
 * @param pattern 模式串
 * @return 首次匹配成功时在主串中的地址
 */
int kmp(char text[], char pattern[]) {

    int len_p = strlen(pattern);
    int len_t = strlen(text);

    int victory_count = 0;
    int first_victory_index = -1;

    int *prefix = new int[len_p];
    // 前缀表
    prefix_table(pattern, prefix, len_p);

    int t = 0;
    int p = 0;
    while (t < len_t) {
        // 匹配成功
        if (p == len_p- 1 && pattern[p] == text[t]) {
            cout << "Found pattern at " << t-p << endl;
            victory_count++;
            if (victory_count == 1){
                first_victory_index = t-p;
            }
            // 继续下一次匹配
            p =  prefix[p];
        }
        if (pattern[p] == text[t]) {
            t++;
            p++;
        } else {
            p = prefix[p];
            if (p == -1) {
                p++;
                t++;
            }
        }
    }
    return first_victory_index;
}