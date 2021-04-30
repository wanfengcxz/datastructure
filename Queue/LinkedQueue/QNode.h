//
// Created by 晚风吹行舟 on 2021/4/29.
//

#ifndef DATASTRUCTURE_QNODE_H
#define DATASTRUCTURE_QNODE_H

using T = int;

struct QNode{

    T data;
    QNode * next;

    QNode(T e = 0):data(e),next(nullptr){

    }

};


#endif //DATASTRUCTURE_QNODE_H
