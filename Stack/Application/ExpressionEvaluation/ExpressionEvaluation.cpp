//
// Created by 晚风吹行舟 on 2021/5/2.
//
#include "../../LinkedStack/LinkedStack.h"
#include "../../LinkedStack/LinkedStack.cpp"
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

inline bool isLetter(char e);

inline bool isOP(char e);

inline bool isDigit(char e);

std::vector<std::string> parseFormula_digit(std::string formula);


/**
 * 对于含有"x","+","-","/","(",")“，”0-9“的表达式进行求值 假设给定的都是正确的中缀表达式
 * @param target 要进行求值的表达式
 * @return 求值结果
 */
double ExpressionEvaluation(std::string target) {

    std::stack<double> s;
    std::vector<std::string> postfixExpression = parseFormula_digit(target);
    if (postfixExpression.size() == 0) {
        return 99999.0;
    }
    double res = 0;
    for (int i = 0; i < postfixExpression.size(); i++) {
        const char *temp = postfixExpression[i].c_str();
        if (isOP(temp[0])) {
            // 如果是操作符，取栈顶的两个数字进行运算
            if (s.empty()) return 99999.0;
            res = s.top();
            s.pop();
            if (s.empty()) return 99999.0;
            switch(temp[0]){
                case '+':
                    res = s.top()+res;
                    break;
                case '-':
                    res = s.top()-res;
                    break;
                case '/':
                    res = s.top()/res;
                    break;
                case '*':
                    res = s.top()*res;
                    break;
                default:
                    return 99999.0;
            }
            s.pop();
            s.push(res);
        } else {
            // 如果是数字，入栈
            s.push(std::stod(temp));
        };
    }
    s.pop();
    if (s.empty())
        return res;
    else
        return 99999.0;
}

/**
 * 中缀表达式转换为后缀表达式 假设给定的都是正确的中缀表达式
 * 其中中缀表达式含有"x","+","-","/","(",")“，”0-9“字符
 * @param formula 要进行转换的中缀表达式
 * @return 后缀表达式
 */
std::vector<std::string> parseFormula_digit(std::string formula) {
    std::stack<char> op_stack;
    std::vector<std::string> result;
    std::unordered_map<char, int> priority_map;
    priority_map['+'] = 1;
    priority_map['-'] = 1;
    priority_map['*'] = 2;
    priority_map['/'] = 2;
    priority_map['('] = 0;

    for (int i = 0; i < formula.length(); i++) {
        if (isDigit(formula[i])) {
            // 提取数字
            int num = static_cast<int>(formula[i++] - '0');
            while (isDigit(formula[i])) {
                num = num * 10 + static_cast<int>(formula[i++] - '0');
            }
            i--;
            result.push_back(std::to_string(num));
        } else if (isOP(formula[i])) {
            // formula[i]为运算符
            // 与op_stack中的运算符比较优先级
            while (!op_stack.empty()) {
                // 栈顶的运算符优先级大于或等于当前运算符
                if (priority_map[op_stack.top()] >= priority_map[formula[i]]) {
                    result.emplace_back(std::string(1, op_stack.top()));
                    op_stack.pop();
                } else {
                    break;
                }
            }
            // 栈为空或者栈顶的运算符优先级小于当前运算符
            op_stack.push(formula[i]);
        } else if (formula[i] == '(') {
            op_stack.push(formula[i]);
        } else if (formula[i] == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                result.emplace_back(std::string(1, op_stack.top()));
                op_stack.pop();
            }
            if (op_stack.empty()) {
                return std::vector<std::string>();
            } else {
                op_stack.pop();
            }
        } else {
            return std::vector<std::string>();
        };
    }
    while (!op_stack.empty()) {
        result.emplace_back(std::string(1, op_stack.top()));
        op_stack.pop();
    }
    return result;
}

/**
 * 中缀表达式转换为后缀表达式 假设给定的都是正确的中缀表达式
 * 其中中缀表达式含有"x","+","-","/","(",")“，”a-z“字符
 * @param formula 要进行转换的中缀表达式
 * @return 后缀表达式
 */
std::string parseFormula_letter(std::string formula) {
    std::stack<char> op_stack;
    std::string result = std::string();
    std::unordered_map<char, int> priority_map;
    priority_map['+'] = 1;
    priority_map['-'] = 1;
    priority_map['*'] = 2;
    priority_map['/'] = 2;
    priority_map['('] = 0;

    for (int i = 0; i < formula.length(); i++) {

        if (isLetter(formula[i])) {
            // formula[i]为字母直接入栈
            result += formula[i];
        } else if (isOP(formula[i])) {
            // formula[i]为运算符
            // 与op_stack中的运算符比较优先级
            while (!op_stack.empty()) {
                // 栈顶的运算符优先级大于或等于当前运算符
                if (priority_map[op_stack.top()] >= priority_map[formula[i]]) {
                    result += op_stack.top();
                    op_stack.pop();
                } else {
                    break;
                }
            }
            // 栈为空或者栈顶的运算符优先级小于当前运算符
            op_stack.push(formula[i]);
        } else if (formula[i] == '(') {
            op_stack.push(formula[i]);
        } else if (formula[i] == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                result += op_stack.top();
                op_stack.pop();
            }
            if (op_stack.empty()) {
                return std::string();
            } else {
                op_stack.pop();
            }
        } else {
            return std::string();
        };
    }
    while (!op_stack.empty()) {
        result += op_stack.top();
        op_stack.pop();
    }
    return result;
}

inline bool isOP(char e) {
    return e == '/' || e == '*' || e == '+' || e == '-';
}

inline bool isLetter(char e) {
    return 'a' <= e && e <= 'z';
}

bool isDigit(char e) {
    return e >= '0' && e <= '9';
}


