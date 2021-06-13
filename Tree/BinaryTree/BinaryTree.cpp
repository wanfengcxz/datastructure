//
// Created by 晚风吹行舟 on 2021/5/7.
//

#include <sstream>
#include "BinaryTree.h"

template<typename T>
int heightRecur(BiTNode<T> *head) {
    int left = 0, right = 0;
    if (head == nullptr)
        return 0;
    left = heightRecur<T>(head->lchild) + 1;
    right = heightRecur<T>(head->rchild) + 1;
    return left > right ? left : right;
}

template<typename T>
int BinaryTree<T>::height() {
    // 递归
//    return = heightRecur<T>(this->_head);
    // 迭代 层次遍历
    int height = 0;
    queue<BiTNode<T> *> q;
    BiTNode<T> *tmp = _head;
    q.push(tmp);
    while (!q.empty()) {
        height++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            tmp = q.front();
            q.pop();
            if (tmp->lchild != nullptr)
                q.push(tmp->lchild);
            if (tmp->rchild != nullptr)
                q.push(tmp->rchild);
        }
    }
    return height;
}

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
    preorderTraversal_recur<T>(this->_head, res);
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
    postorderTraversal_recur<T>(this->_head, res);
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
    inorderTraversal_recur<T>(this->_head, res);
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
        } else {
            if (cur->rchild != nullptr)
                s.push(cur->rchild);
            if (cur->lchild != nullptr)
                s.push(cur->lchild);
        }
    }
    return;
}

template<typename T>
void BinaryTree<T>::levelTraversal(vector<T> &res) {
    queue<BiTNode<T> *> q;
    BiTNode<T> *tmp = _head;

    q.push(tmp);
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        res.emplace_back(tmp->data);
        if (tmp->lchild != nullptr)
            q.push(tmp->lchild);
        if (tmp->rchild != nullptr)
            q.push(tmp->rchild);
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
    // 掐头去尾 []
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

template<typename T>
void inThread(BiTNode<T> *cur, BiTNode<T> *&pre) {
    if (cur != nullptr) {
        inThread(cur->lchild, pre);
        if (cur->lchild == nullptr) {
            cur->lchild = pre;
            cur->ltag = 1;
        }
        if (pre != nullptr && pre->rchild == nullptr) {
            pre->rchild = cur;
            pre->rtag = 1;
        }
        pre = cur;
        inThread(cur->rchild, pre);
    }
}

template<typename T>
void BinaryTree<T>::inOrderThreading() {
    BiTNode<T> *pre = nullptr;
    if (_head != nullptr) {
        inThread(_head, pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}

template<typename T>
BiTNode<T> *BinaryTree<T>::firstNode(BiTNode<T> *p) {
    while (p->ltag == 0) p = p->lchild;
    return p;
}

template<typename T>
BiTNode<T> *BinaryTree<T>::nextNode(BiTNode<T> *p) {
    if (p->rtag == 0) return firstNode(p->rchild);
    return p->rchild;
}

template<typename T>
void BinaryTree<T>::inOrder(vector<T> &res) {
    BiTNode<T> *tmp = firstNode(_head);
    while (tmp != nullptr) {
        res.emplace_back(tmp->data);
        tmp = nextNode(tmp);
    }
}

template<typename T>
bool isFullBinaryTreeRecur(BiTNode<T> *node) {
    if (node == nullptr) {
        return false;
    }
    if (node->rchild == nullptr && node->lchild == nullptr)
        return true;
    if (node->lchild != nullptr || node->rchild != nullptr)
        return isFullBinaryTreeRecur<T>(node->rchild) && isFullBinaryTreeRecur<T>(node->lchild);
    return false;
}

template<typename T>
bool BinaryTree<T>::isFullBinaryTree() {
    if (_head == nullptr)
        return false;
    queue<BiTNode<T> *> q;
    BiTNode<T> *tmp = _head;
    int right_size = 1;

    q.push(tmp);
    while (!q.empty()) {
        int size = q.size();
        if (size == right_size){
            right_size *= 2;
        }else
            return false;
        for (int i = 0; i < size; i++) {
            tmp = q.front();
            q.pop();
            if (tmp->lchild != nullptr)
                q.push(tmp->lchild);
            if (tmp->rchild != nullptr)
                q.push(tmp->rchild);
        }
    }

    return true;
}

template<typename T>
bool BinaryTree<T>::isCompleteBinaryTree() {
    if (_head == nullptr)
        return false;
    queue<BiTNode<T> *> q;
    BiTNode<T> * tmp = _head;
    q.push(tmp);
    bool isAllEmpty = false;
    while (!q.empty()){
        int size = q.size();
        for (int i = 0;i<size;i++){
            tmp = q.front();
            q.pop();
            if (isAllEmpty && tmp->lchild != nullptr)
                return false;
            if (tmp->lchild == nullptr)
                isAllEmpty = true;
            else
                q.push(tmp->lchild);
            if (isAllEmpty && tmp->rchild != nullptr)
                return false;
            if (tmp->rchild == nullptr)
                isAllEmpty = true;
            else
                q.push(tmp->rchild);
        }
    }
    return true;
}


