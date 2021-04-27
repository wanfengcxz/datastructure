//
// Created by 晚风吹行舟 on 2021/4/27.
//

#include "ShareStack.h"

template<typename T>
bool ShareStack<T>::push(T e, int flag) {
    if (top2 - top1 == 1) {
        return false;
    }

    if (flag == 1) {
        data[++top1] = e;
        return true;
    } else if (flag == 2) {
        data[--top2] = e;
        return true;
    } else {
        return false;
    }

}

template<typename T>
bool ShareStack<T>::empty(int flag) {
    if (flag == 1) {
        return top1 == -1;
    } else if (flag == 2) {
        return top2 == MaxSize;
    } else {
        return false;
    }
}

template<typename T>
bool ShareStack<T>::pop(int flag) {
    if (empty(flag)) {
        return false;
    }
    if (flag == 1) {
        top1--;
        return true;
    } else if (flag == 2) {
        top2++;
        return true;
    } else {
        return false;
    }
}

template<typename T>
bool ShareStack<T>::top(T &e, int flag) {
    if (empty(flag)) {
        return false;
    }
    if (flag == 1) {
        e = data[top1];
        return true;
    } else if (flag == 2) {
        e = data[top2];
        return true;
    } else {
        return false;
    }
}
