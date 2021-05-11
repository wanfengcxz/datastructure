//
// Created by 晚风吹行舟 on 2021/5/7.
//
template<typename T>
struct BiTNode {
    T data;
    BiTNode<T> *lchild;
    BiTNode<T> *rchild;
    // BitNode *lchild ?

    explicit BiTNode(T data) : data(data), lchild(nullptr), rchild(nullptr) {}


};

