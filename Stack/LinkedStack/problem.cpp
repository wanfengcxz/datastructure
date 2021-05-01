//
// Created by 晚风吹行舟 on 2021/5/1.
//
#include "LinkedStack.h"
#include "LinkedStack.cpp"

/**
 * 两个栈来模拟队列
 * P80 二.3
 */
class Queue2S {

private:
    LinkedStack s1, s2;

public:

    Queue2S() {}

    bool push(int e);

    bool pop(int &e);

    bool empty();

};

bool Queue2S::push(int e) {
    s1.push(e);
    return true;
}

bool Queue2S::pop(int &e) {
    int value = 0;
    if (s2.empty()) {
        while (s1.top(value)) {
            s2.push(value);
            s1.pop();
        }
    }
    if (s2.empty()) {
        return false;
    } else {
        s2.top(e);
        s2.pop();
        return true;
    }
}

bool Queue2S::empty() {
    return s1.empty() && s2.empty();
}
