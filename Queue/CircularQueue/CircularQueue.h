//
// Created by 晚风吹行舟 on 2021/4/27.
//

#ifndef DATASTRUCTURE_CIRCULARQUEUE_H
#define DATASTRUCTURE_CIRCULARQUEUE_H

template<class T>
class CircularQueue {
private:
    static const int MaxSize = 6;
private:

    T data[MaxSize];
    int front_;
    int rear_;

public:

    CircularQueue():rear_(0), front_(0){

    }

    bool front(T &e);

    bool back(T &e);

    bool push(T e);

    bool pop();

    int size();

    bool empty();

};



#endif //DATASTRUCTURE_CIRCULARQUEUE_H
