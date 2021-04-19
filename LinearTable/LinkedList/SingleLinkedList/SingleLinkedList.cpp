//
// Created by 晚风吹行舟 on 2021/4/17.
//

#include "SingleLinkedList.h"

void SingleLinkedList::headInsert(T *data, int len) {
    for (int i = 0; i < len; i++) {
        this->headInsert(data[i]);
    }
}

void SingleLinkedList::tailInsert(T *data, int len) {
    LNode *r = head;
    LNode *temp;
    for (int i = 0; i < len; i++) {
        temp = new LNode(data[i]);
        r->next = temp;
        r = r->next;
    }
    r->next = nullptr;
    head->data += len;
}

LNode *SingleLinkedList::getElem(int i) {
    if (i < 0 || i > head->data) return nullptr;
    LNode *temp = head;
    for (int j = 0; j < i; j++) {
        temp = temp->next;
    }
    return temp;
}

LNode *SingleLinkedList::locateElem(T e) {
    LNode *temp = head;
    int len = head->data;
    for (int i = 0; i < len; i++) {
        temp = temp->next;
        if (temp->data == e) {
            return temp;
        }
    }
    return nullptr;
}

bool SingleLinkedList::insertElem(int i, T e) {
    //    get the node i-1
    LNode *pre = this->getElem(i - 1);
//    if (i < 1 || i > head->data + 1) return false;
//    LNode *pre = head;
//    for (int j = 0; j < i - 1; j++) {
//        pre = pre->next;
//    }
    if (pre == nullptr) return false;
    LNode *temp = new LNode(e); // 如果放在if之前就会造成内存泄漏
    temp->next = pre->next;
    pre->next = temp;
    head->data++;
    return true;
}

bool SingleLinkedList::insertElem(int i, T e, int) {
    if (i < 1 || i > head->data+1) return false;
    if (i == head->data+1){
        this->getElem(i-1)->next = new LNode(e);
        head->data++;
        return true;
    }
    LNode *pre = this->getElem(i), *temp = new LNode(pre->data);
    temp->next = pre->next;
    pre->next = temp;
    pre->data = e;
    head->data++;
    return true;
}

bool SingleLinkedList::deleteElem(int i, T &e) {
    if (i<1 ||i > head->data){
        return false;
    }
    LNode *pre = this->getElem(i-1), *temp = pre->next;
    e = pre->next->data;
    pre->next = pre->next->next;
    delete temp;
    head->data--;
    return true;
}





