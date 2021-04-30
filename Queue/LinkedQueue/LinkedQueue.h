//
// Created by 晚风吹行舟 on 2021/4/28.
//

#ifndef DATASTRUCTURE_LINKEDQUEUE_H
#define DATASTRUCTURE_LINKEDQUEUE_H

#include "QNode.h"

// 含有头节点
class LinkedQueue {
private:
    QNode *front_;
    QNode *rear_;

public:

    LinkedQueue() : front_(new QNode(0)), rear_(nullptr) {

    }

    bool front(T &e);

    bool back(T &e);

    bool push(T e);

    bool pop();

    int size();

    bool empty();

};


#endif //DATASTRUCTURE_LINKEDQUEUE_H
