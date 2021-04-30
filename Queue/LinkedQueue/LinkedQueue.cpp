//
// Created by 晚风吹行舟 on 2021/4/28.
//

#include "LinkedQueue.h"

bool LinkedQueue::front(T &e) {
    if (empty()) {
        return false;
    } else {
        e = front_->next->data;
        return true;
    }

}

bool LinkedQueue::back(T &e) {
    if (empty()) {
        return false;
    } else {
        e = rear_->data;
        return true;
    }
}

bool LinkedQueue::push(T e) {
    if (rear_ == nullptr) {
        rear_ = new QNode(e);
        front_->next = rear_;
        front_->data++;
        return true;
    }
    rear_->next = new QNode(e);
    rear_ = rear_->next;
    front_->data++;
    return true;
}

bool LinkedQueue::pop() {
    if (empty()) {
        return false;
    } else {
        QNode *temp = front_->next->next;
        delete front_->next;
        front_->next = temp;
        front_->data--;
        if (front_->data == 0){
            rear_ = nullptr;
        }
        return true;
    }
}

int LinkedQueue::size() {
    return front_->data;
}

bool LinkedQueue::empty() {
    return rear_ == nullptr;
}
