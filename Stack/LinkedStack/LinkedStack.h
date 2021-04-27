//
// Created by 晚风吹行舟 on 2021/4/27.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H
#define DATASTRUCTURE_LINKEDSTACK_H

#include "LinkedStackNode.h"


class LinkedStack {

private:
    LinkedStackNode * head;

public:
    LinkedStack():head(nullptr){
    }

    bool push(T e);

    bool pop();

    bool top(T &e);

    bool empty();

};


#endif //DATASTRUCTURE_LINKEDSTACK_H
