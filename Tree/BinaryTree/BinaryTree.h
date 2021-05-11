//
// Created by 晚风吹行舟 on 2021/5/7.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include "BiTNode.h"
#include <vector>

using std::vector;


template<typename T>
class BinaryTree {
public:
    static const int null = 9999;

private:
    BiTNode<T> *_head;

public:
    explicit BinaryTree() : _head(nullptr) {}

    BiTNode<T> * head(){
        return _head;
    };

    void initBinaryTree();

    void createTreeByArray(T arr[]);

    // 前序遍历
    void preorderTraversalRecur(vector<T> &res);

    // 后序遍历
    void postorderTraversalRecur(vector<T> &res);

    // 中序遍历
    void inorderTraversalRecur(vector<T> &res);


};



#endif //DATASTRUCTURE_BINARYTREE_H
