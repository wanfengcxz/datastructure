//
// Created by 晚风吹行舟 on 2021/4/20.
//

#ifndef DATASTRUCTURE_STATICLINKEDLIST_H
#define DATASTRUCTURE_STATICLINKEDLIST_H
#include "SNode.h"

const int MaxSize = 100;

class StaticLinkedList {
private:
    SNode list[MaxSize];

public:
    StaticLinkedList(){
        for (int i = 1;i<MaxSize-2;i++){
            list[i].next = i+1;
        }

        list[0].next = 1;

    }

};


#endif //DATASTRUCTURE_STATICLINKEDLIST_H
