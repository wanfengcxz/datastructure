//
// Created by 晚风吹行舟 on 2021/4/21.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H

using T = int;

class SqStack {

private:
    static const int MaxSize = 5;
    T data[MaxSize];
    int top_;

public:

    SqStack():top_(-1){

    }

    ~SqStack(){

    }

    bool empty();

    bool push(T e);

    bool top(T &e);

    bool pop();


};


#endif //DATASTRUCTURE_SQSTACK_H
