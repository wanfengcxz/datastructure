//
// Created by 晚风吹行舟 on 2021/4/27.
//

#include "CircularQueue.h"

template<class T>
bool CircularQueue<T>::front(T &e) {
    if (empty()) {
        return false;
    } else {
        e = data[front_];
        return true;
    }
}

template<class T>
bool CircularQueue<T>::back(T &e) {
    if (empty()) {
        return false;
    } else {
        e = data[rear_-1];
        return true;
    }
}

template<class T>
bool CircularQueue<T>::push(T e) {
    if ((rear_ + 1) % MaxSize == front_) {
        return false;
    } else {
        data[rear_] = e;
        rear_ = (rear_ + 1) % MaxSize;
        return true;
    }
}

template<class T>
bool CircularQueue<T>::pop() {
    if (empty()) {
        return false;
    } else {
        front_ = (front_ + 1) % MaxSize;
        return true;
    }
}

template<class T>
int CircularQueue<T>::size() {
    return (rear_ + MaxSize - front_) % MaxSize;
}

template<class T>
bool CircularQueue<T>::empty() {
    return rear_ == front_;
}
