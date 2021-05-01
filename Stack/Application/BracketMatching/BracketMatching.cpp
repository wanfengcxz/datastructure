//
// Created by 晚风吹行舟 on 2021/5/1.
//
#include "../../LinkedStack/LinkedStack.h"
#include "../../LinkedStack/LinkedStack.cpp"
#include <string>

using namespace std;

bool BracketMatching(string target) {
    LinkedStack<char> stack;
    char temp = '1';
    for (int i = 0; i < target.size(); i++) {
        // 如果是左侧括号，直接入栈，然后判断下一个字符
        if (target[i] == '(' || target[i] == '[') {
            stack.push(target[i]);
        } else {
            // 如果是右侧括号
            if (target[i] == ')' || target[i] == ']') {
                // 此时栈空，则无法匹配，返回错误
                if (stack.empty())
                    return false;
                // 栈不为空
                stack.top(temp);
                // 能够匹配成功
                if (temp+1 == target[i] || temp+2 == target[i]) {
                    // 出栈，然后判断下一个字符
                    stack.pop();
                } else {
                    // 匹配失败，返回错误
                    return false;
                }
                // 出现不明字符，返回错误
            } else {
                return false;
            }
        }
    }

    return stack.empty();
}


