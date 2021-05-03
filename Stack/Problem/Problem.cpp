//
// Created by 晚风吹行舟 on 2021/5/3.
//
#include <string>
#include <stack>
#include <iostream>
#include "../LinkedStack/LinkedStack.h"
#include "../LinkedStack/LinkedStack.cpp"

using namespace std;

/**
 * 两个栈来模拟队列
 * P80 二.3
 */
class Queue2S {

private:
    LinkedStack<int> s1, s2;

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


/**
 * 车厢调度
 * H为硬座车厢 S为软座车厢
 * 有一车厢序列，通过调度站进行调度，使得软座车厢都在硬座车厢的前面
 * @param car_seq 车厢序列
 * @return 调度后的序列
 */
string CarDispatching(string car_seq) {
    stack<char> s;
    string res;
    for (int i = 0; i < car_seq.size(); i++) {
        if (car_seq[i] == 'H') {
            s.push(car_seq[i]);
            cout << car_seq[i] << "进站" << endl;
        } else {
            s.push(car_seq[i]);
            cout << car_seq[i] << "进站" << endl;
            s.pop();
            res += car_seq[i];
            cout << car_seq[i] << "出站" << endl;
        }
    }
    while (!s.empty()){
        res += s.top();
        cout << s.top() << "出站" << endl;
        s.pop();
    }
    cout << endl;
    return res;
}

