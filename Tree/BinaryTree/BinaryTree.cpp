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
    BiTNode<int> *tmp = new BiTNode<int>(1);
    _head = tmp;
    tmp = new BiTNode<int>(2);
    _head->lchild = tmp;
    tmp = new BiTNode<int>(3);
    _head->rchild = tmp;
    tmp = new BiTNode<int>(4);
    _head->lchild->lchild = tmp;
    tmp = new BiTNode<int>(6);
    _head->rchild->lchild = tmp;
    tmp = new BiTNode<int>(7);
    _head->rchild->rchild = tmp;

}

template<typename T>
void BinaryTree<T>::preorderTraversal(vector<T> &res) {
//    if (_head == nullptr)
//        return;
//    BiTNode<T> *tmp = _head;
//    stack<BiTNode<T> *> s;
//    while (tmp != nullptr || !s.empty()) {
//        if (tmp != nullptr) {
//            res.emplace_back(tmp->data);
//            s.emplace(tmp->rchild);
//            s.emplace(tmp->lchild);
//        }
//        tmp = s.top();
//        s.pop();
//    }
//    return;
    if (_head == nullptr)
        return;
    BiTNode<T> *tmp = _head;
    stack<BiTNode<T> *> s;
    while (tmp != nullptr || !s.empty()) {
        while (tmp != nullptr) {
            s.push(tmp);
            // 第一次遇到就将其添加到结果中
            res.emplace_back(tmp->data);
            tmp = tmp->lchild;
        }
        if (!s.empty()) {
            tmp = s.top();
            s.pop();
            tmp = tmp->rchild;
        }
    }
    return;
}

template<typename T>
void BinaryTree<T>::inorderTraversal(vector<T> &res) {
    if (_head == nullptr)
        return;
    BiTNode<T> *tmp = _head;
    stack<BiTNode<T> *> s;
    while (tmp != nullptr || !s.empty()) {
        while (tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->lchild;
        }
        if (!s.empty()) {
            tmp = s.top();
            // 第二次遇到就将其添加到结果中
            res.emplace_back(tmp->data);
            s.pop();
            tmp = tmp->rchild;
        }
    }
    return;
}

template<typename T>
void BinaryTree<T>::postorderTraversal(vector<T> &res) {
    /**
     * 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
     * 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，
     * 但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
     * 若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，
     * 左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
     */
    if (_head == nullptr)
        return;
    BiTNode<T> *cur = _head, *pre = nullptr;
    stack<BiTNode<T> *> s;
    s.push(cur);
    while (!s.empty()) {
        cur = s.top();
        if ((cur->lchild == nullptr && cur->rchild == nullptr) ||
            ((pre == cur->lchild || pre == cur->rchild) && pre != nullptr)) {
            res.emplace_back(cur->data);
            s.pop();
            pre = cur;
        }
        else{
            if (cur->rchild != nullptr)
                s.push(cur->rchild);
            if (cur->lchild != nullptr)
                s.push(cur->lchild);
        }
    }
    return;
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
