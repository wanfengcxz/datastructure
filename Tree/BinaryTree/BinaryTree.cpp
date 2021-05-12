//
// Created by 晚风吹行舟 on 2021/5/7.
//

#include "BinaryTree.h"

template<typename T>
void preorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head != nullptr) {
        res.emplace_back(head->data);
        preorderTraversal_recur(head->lchild, res);
        preorderTraversal_recur(head->rchild, res);
        return;
    }
}

template<typename T>
void BinaryTree<T>::preorderTraversalRecur(vector<T> &res) {
    preorderTraversal_recur<T>(this->head(), res);
    return;
}

template<typename T>
void postorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head != nullptr) {
        postorderTraversal_recur(head->lchild, res);
        postorderTraversal_recur(head->rchild, res);
        res.emplace_back(head->data);
        return;
    }
}

template<typename T>
void BinaryTree<T>::postorderTraversalRecur(vector<T> &res) {
    postorderTraversal_recur<T>(this->head(), res);
    return;
}


template<typename T>
void inorderTraversal_recur(BiTNode<T> *head, vector<T> &res) {
    if (head != nullptr) {
        inorderTraversal_recur(head->lchild, res);
        res.emplace_back(head->data);
        inorderTraversal_recur(head->rchild, res);
        return;
    }
}

template<typename T>
void BinaryTree<T>::inorderTraversalRecur(vector<T> &res) {
    inorderTraversal_recur<T>(this->head(), res);
    return;
}

template<typename T>
void BinaryTree<T>::createTreeByArray(T *arr) {
    return;
}

// 全特化
template<>
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

template<typename T>
void BinaryTree<T>::postorderTraversal(vector<T> &res) {

}

template<typename T>
void BinaryTree<T>::preorderTraversal(vector<T> &res) {
    if (_head == nullptr)
        return;
    BiTNode<T> *temp = _head;
    stack<BiTNode<T> *> s;
    while (temp != nullptr || !s.empty()) {
        if (temp != nullptr) {
            res.emplace_back(temp->data);
            cout << temp->data << " ";
            s.emplace(temp->rchild);
            s.emplace(temp->lchild);
        }
        temp = s.top();
        s.pop();
    }
    return;
}

template<typename T>
void BinaryTree<T>::inorderTraversal(vector<T> &res) {

}

template<>
string BinaryTree<int>::serialize() {
    string res = "[";
    if (_head == nullptr) {
        res += "]";
        return res;
    }

    queue<BiTNode<int> *> q;
    BiTNode<int> *tmp = nullptr;
    q.emplace(_head);
    while (!q.empty()) {
        int size = q.size();
        bool isNull = true;
        for (int i = 0; i < size; i++) {
            tmp = q.front();
            q.pop();
            if (tmp != nullptr) {
                if (tmp->lchild != nullptr || tmp->rchild != nullptr)
                    isNull = false;
                res += std::to_string(tmp->data) + ",";
                q.emplace(tmp->lchild);
                q.emplace(tmp->rchild);
            } else {
                res += "null,";
            }
        }
        if (isNull)
            break;
    }
    res.pop_back();
    return res + "]";
}

template<>
void BinaryTree<int>::deserialize(string data) {
    if (data == "[]")
        _head = nullptr;

    vector<BiTNode<int> *> tree;
    // 掐头去尾 [ ]
    data.erase(0, 1);
    data.pop_back();
    string buffer;
    istringstream iss(data);

    // string -> BiTNode*
    while (getline(iss, buffer, ',')) {
        if (buffer == "null") {
            tree.emplace_back(nullptr);
        } else {
            tree.emplace_back(new BiTNode<int>(std::stoi(buffer)));
        }
    }

    int pos = 1;
    int size = tree.size();
    for (int i = 0; pos < size; i++) {
        if (tree[i] == nullptr)
            continue;
        tree[i]->lchild = tree[pos++];
        if (pos < size)
            tree[i]->rchild = tree[pos++];
    }
    _head = tree[0];

    return;
}
