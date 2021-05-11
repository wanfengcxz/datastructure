//
// Created by 晚风吹行舟 on 2021/5/7.
//

#include "BinaryTree.h"

template<typename T>
void preorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head == nullptr) {
        return;
    } else {
        res.push_back(head->data);
        preorderTraversal_recur(head->lchild, res);
        preorderTraversal_recur(head->rchild, res);
        return;
    }
}

template<typename T>
void BinaryTree<T>::preorderTraversalRecur(vector<T> &res) {
    preorderTraversal_recur<T>(this->head(), res);
    return ;
}

template<typename T>
void postorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head == nullptr) {
        return;
    } else {
        postorderTraversal_recur(head->lchild, res);
        postorderTraversal_recur(head->rchild, res);
        res.push_back(head->data);
        return;
    }
}

template<typename T>
void BinaryTree<T>::postorderTraversalRecur(vector<T> &res) {
    postorderTraversal_recur<T>(this->head(), res);
    return ;
}


template<typename T>
void inorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head == nullptr) {
        return;
    } else {
        inorderTraversal_recur(head->lchild, res);
        res.push_back(head->data);
        inorderTraversal_recur(head->rchild, res);
        return;
    }
}

template<typename T>
void BinaryTree<T>::inorderTraversalRecur(vector<T> &res) {
    inorderTraversal_recur<T>(this->head(), res);
    return ;
}

template<typename T>
void BinaryTree<T>::createTreeByArray(T *arr) {

    return ;
}

// 全特化0
template< >
void BinaryTree<int>::initBinaryTree() {

    /**
     *      1
     *   2     3
     *  4     6  7
     */
    BiTNode<int> *temp = new BiTNode<int>(1);
    _head = temp;
    temp = new BiTNode<int>(2);
    _head->lchild = temp;
    temp = new BiTNode<int>(3);
    _head->rchild = temp;
    temp = new BiTNode<int>(4);
    _head->lchild->lchild = temp;
    temp = new BiTNode<int>(6);
    _head->rchild->lchild = temp;
    temp = new BiTNode<int>(7);
    _head->rchild->rchild = temp;

}


