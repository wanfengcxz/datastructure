//
// Created by 晚风吹行舟 on 2021/4/27.
//

#include "LinkedStack.h"

bool LinkedStack::push(T e) {
    LinkedStackNode *temp = new LinkedStackNode(e);
    temp->next = head;
    head = temp;
    return true;
}

bool LinkedStack::pop() {
    if (head == nullptr)
        return false;

    LinkedStackNode *temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool LinkedStack::top(T &e) {
    if (head == nullptr)
        return false;
    e = head->data;
    return true;
}

bool LinkedStack::empty() {
    return head == nullptr;
}

