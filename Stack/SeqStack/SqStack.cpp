//
// Created by 晚风吹行舟 on 2021/4/21.
//

#include "SqStack.h"

bool SqStack::empty() {
    return top_==-1;
}

bool SqStack::push(T e) {
    // 短路
    return (top_!=MaxSize-1)&&(data[++top_]=e)==e;
}

bool SqStack::top(T &e) {
    return (top_!=-1)&&(e=data[top_])==e;
}

bool SqStack::pop() {
    return (top_!=-1)&&(--top_)==top_;
}





