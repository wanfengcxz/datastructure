//
// Created by 晚风吹行舟 on 2021/5/1.
//
#include "../../LinkedStack/LinkedStack.h"
#include "../../LinkedStack/LinkedStack.cpp"
#include <string>
#include <stack>

using namespace std;

/**
 * 括号匹配 给定的表达式仅限于[]()
 * eg: ([([])([[]])]())
 * @param target 要检测的表达式
 * @return  是否完全配对
 */
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
                if (temp + 1 == target[i] || temp + 2 == target[i]) {
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

inline bool isLeftBracket(char e);

inline bool isRightBracket(char e);

/**
 * P90 二.1
 * 算术表达式的括号匹配 括号仅限于{}[]()
 * eg: (2+3)*3-{3-[2+3/(2+2)]}
 * @param target 要检测的算术表达式
 * @return 括号是否完全匹配
 */
bool BracketMatching_3(string target) {

    stack<char> s;
    for (int i = 0; i < target.length(); i++) {
        if (isLeftBracket(target[i])) {
            s.push(target[i]);
        } else if (isRightBracket(target[i])) {
            // 栈中字符和当前字符相同,即为配对成功
            if (char(s.top()+1) == target[i] || char(s.top()+2) == target[i]) {
                s.pop();
            } else {
                // 若不相同，则匹配失败
                return false;
            }
        }
    }
    if (s.empty()) {
        return true;
    } else {
        return false;
    }

}

inline bool isLeftBracket(char e) {
    return e == '(' || e == '[' || e == '{';
}

bool isRightBracket(char e) {
    return e == ')' || e == ']' || e == '}';
}