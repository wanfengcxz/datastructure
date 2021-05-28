//
// Created by 晚风吹行舟 on 2021/5/21.
//

#include "BST.h"

template<typename T>
BiTNode<T> *BST<T>::search(T key) {
    BiTNode<T> *node = this->_head;
    while (node != nullptr && key != node->data) {
        if (key > node->data) node = node->rchild;
        else node = node->lchild;
    }
    return node;
}

template<class T>
int insert_recur(BiTNode<T> *&head, T key) {
    if (head == nullptr) {
        head = new BiTNode<T>(key);
        return 1;
    }
    if (head->data == key)
        return 0;
    else if (head->data > key)
        return insert_recur<T>(head->lchild, key);
    else
        return insert_recur<T>(head->rchild, key);
}

template<class T>
int BST<T>::insertNode(T key) {
    return insert_recur<T>(this->_head, key);
}

template<class T>
void BST<T>::createBST(vector<T> arr) {
    for (int i = 0; i < arr.size(); i++)
        this->insertNode(arr[i]);
}

template<typename T>
BiTNode<T> *deleteNode_recur(BiTNode<T> *root, T key) {

    if (root == nullptr) return nullptr;
    if (root->data > key) root->lchild = deleteNode_recur(root->lchild, key);
    else if (root->data < key) root->rchild = deleteNode_recur(root->rchild, key);
    else {
        // 当前节点就是要删除的节点
        // 左右子树都为空
        if (root->lchild == nullptr && root->rchild == nullptr) {
            delete root;
            return nullptr;
            // 左子树为空 右子树不为空
        } else if (root->lchild == nullptr) {
            BiTNode<T> *tmp = root->rchild;
            delete root;
            return tmp;
            // 右子树为空 左子树不为空
        } else if (root->rchild == nullptr) {
            BiTNode<T> *tmp = root->lchild;
            delete root;
            return tmp;
        } else {
            // 获取当前节点右子树的最左侧节点
            BiTNode<T> *tmp = root->rchild;
            while (tmp->lchild != nullptr)
                tmp = tmp->lchild;
            tmp->lchild = root->lchild;
            // 保存右节点
            tmp = root->rchild;
            delete root;
            root = tmp;
        }
    }
    return root;
}
// 废弃的deleteNode 花了好长时间来debug 不舍得删罢了
//    if (root == nullptr) return false;
//    // 去左子树中删除
//    if (root->data > key) return deleteNode_recur(root->lchild, key);
//    // 去右子树中删除
//    else if (root->data < key) return deleteNode_recur(root->rchild, key);
//    else {
//        // 左右子树都为空 则直接删除
//        if (root->rchild == nullptr && root->lchild == nullptr) {
//            BiTNode<T> * tmp = this->getParent(root->data);
//            if (tmp->rchild->data == root->data)
//                tmp->rchild = nullptr;
//            else
//                tmp->lchild = nullptr;
//            delete root;
//            return true;
//            // 右子树不为空 则右子树顶替当前位置
//        } else if (root->rchild != nullptr) {
//            BiTNode<T> * tmp = this->getParent(root->data);
//            if (tmp->rchild->data == root->data)
//                tmp->rchild = root->rchild;
//            else
//                tmp->lchild = root->rchild;
//            delete root;
//            return ture;
//            // 左子树不为空 则左子树顶替当前位置
//        } else if (root->lchild != nullptr){
//            BiTNode<T> * tmp = this->getParent(root->data);
//            if (tmp->rchild->data == root->data)
//                tmp->rchild = root->lchild;
//            else
//                tmp->lchild = root->lchild;
//            delete root;
//            return ture;
//            // 左右子树都不为空 将左子树转移到右子树最左侧节点的左子树上
//            // 然后右子树顶替其位置
//        } else{
//            BiTNode<T> * tmp = this->successor(root);
//            tmp->lchild = root->lchild;
//            _head = root->rchild;
//            delete root;
//            return true;
//        }
//    }

template<typename T>
bool BST<T>::deleteNode(T key) {
    if (this->_head == nullptr)
        return false;
    BiTNode<T> *tmp = deleteNode_recur(this->_head, key);
    if (tmp == nullptr)
        return false;
    this->_head = tmp;
    return true;
}

template<typename T>
BiTNode<T> *BST<T>::getParent(T key) {
    BiTNode<T> *node = this->_head;
    stack<BiTNode<T> *> s;
    int count = 0;
    while (node != nullptr) {
        if (key > node->data) {
            s.push(node);
            node = node->rchild;
        } else if (key < node->data) {
            s.push(node);
            node = node->lchild;
        } else {
            return s.top();
        }
    }
    return this->_head;
}

template<typename T>
bool BST<T>::isExist(T key) {
    if (this->_head == nullptr)
        return false;
    BiTNode<T> *node = this->_head;
    while (node != nullptr){
        if (node->data > key)
            node = node->lchild;
        else if (node->data < key)
            node = node->rchild;
        else
            return true;
    }
    return false;
}



