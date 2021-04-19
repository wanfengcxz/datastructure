//
// Created by 晚风吹行舟 on 2021/4/17.
//

#ifndef DATASTRUCTURE_LNODE_H
#define DATASTRUCTURE_LNODE_H

using T = int;

struct LNode{
    T data;
    LNode * next;

    LNode(int data_ = 0):data(data_),next(nullptr){

    }

};

#endif //DATASTRUCTURE_LNODE_H
