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
    int _height;

public:
    explicit BinaryTree() : _head(nullptr),_height(-1) {}

    BiTNode<T> * head(){
        return _head;
    };

    void initBinaryTree();

    void createTreeByArray(T arr[]);

    int height();

    // 前序遍历 递归
    void preorderTraversalRecur(vector<T> &res);

    // 中序遍历 递归
    void inorderTraversalRecur(vector<T> &res);

    // 后序遍历 递归
    void postorderTraversalRecur(vector<T> &res);

    // 前序遍历 迭代
    void preorderTraversal(vector<T> &res);

    // 中序遍历 迭代
    void inorderTraversal(vector<T> &res);

    // 后序遍历 迭代
    void postorderTraversal(vector<T> &res);

    // 层次遍历
    void levelTraversal(vector<T> &res);

    // 序列化 层次序列化 BFS
    string serialize();

    // 反序列化
    void deserialize(string data);


};



#endif //DATASTRUCTURE_BINARYTREE_H
