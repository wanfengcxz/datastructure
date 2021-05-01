//
// Created by 晚风吹行舟 on 2021/4/27.
//

#include "LinkedStack.h"

template<typename T>
bool LinkedStack<T>::push(T e) {
    LinkedStackNode<T> *temp = new LinkedStackNode<T>(e);
    temp->next = head;
    head = temp;
    return true;
}

template<typename T>
bool LinkedStack<T>::pop() {
    if (head == nullptr)
        return false;

    LinkedStackNode<T> *temp = head;
    head = head->next;
    delete temp;
    return true;
}

template<typename T>
bool LinkedStack<T>::top(T &e) {
    if (head == nullptr)
        return false;
    e = head->data;
    return true;
}

template<typename T>
bool LinkedStack<T>::empty() {
    return head == nullptr;
}

