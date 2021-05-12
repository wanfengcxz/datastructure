//
// Created by 晚风吹行舟 on 2021/5/7.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include "BiTNode.h"
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <queue>

using std::istringstream;
using std::queue;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::string;

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

    // 前序遍历 递归
    void preorderTraversalRecur(vector<T> &res);

    // 后序遍历 递归
    void postorderTraversalRecur(vector<T> &res);

    // 中序遍历 递归
    void inorderTraversalRecur(vector<T> &res);

    // 前序遍历 非递归
    void preorderTraversal(vector<T> &res);

    // 中序遍历 非递归
    void inorderTraversal(vector<T> &res);

    // 后序遍历 非递归
    void postorderTraversal(vector<T> &res);

    // 序列化 DFS
    string serialize();

    // 反序列化
    void deserialize(string data);


};



#endif //DATASTRUCTURE_BINARYTREE_H
