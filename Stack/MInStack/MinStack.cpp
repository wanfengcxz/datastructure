//
// Created by 晚风吹行舟 on 2021/5/4.
//

// leetcode 155
class MinStack {
public:
    stack<int> s;
    stack<int> min;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        s.push(val);
        if (min.empty()){
            min.push(val);
        }
        else
        {
            if(min.top() >= val){
                min.push(val);
            }
        }
    }

    void pop() {
        if (s.top() == min.top()){
            min.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};
