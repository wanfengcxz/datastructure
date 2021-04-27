//
// Created by 晚风吹行舟 on 2021/4/27.
//

#ifndef DATASTRUCTURE_SHARESTACK_H
#define DATASTRUCTURE_SHARESTACK_H

const int MaxSize = 5;

/**
 * P66 5.
 * @tparam T type
 */
template<typename T>
class ShareStack {

private:
    T data[MaxSize];
    int top1;
    int top2;

public:
    ShareStack():top1(-1), top2(MaxSize){

    }

    /**
     * is stack empty
     * @param flag stack1 or stack2
     * @return is empty
     */
    bool empty(int flag);

    bool push(T e, int flag);

    bool pop(int flag);

    bool top(T &e, int flag);

};




#endif //DATASTRUCTURE_SHARESTACK_H
