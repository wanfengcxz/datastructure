//
// Created by 晚风吹行舟 on 2021/4/23.
// 课后习题
//
#include "../LNode.h"

// 不带头节点
class SingleLList {

private:
    LNode *head;
public:
    SingleLList() : head(nullptr) {

    }

    /**
     * 头插法
     * @param e 数组
     */
    void headInsert(int e[], int len) {
        for (int i = 0; i < len; i++) {
            LNode *temp = new LNode(e[i]);
            temp->next = head;
            head = temp;
        }
    };

    LNode *getElem(int i) {
        if (i <= 0) return nullptr;
        LNode *p = head;
        while (p && i > 1) {
            p = p->next;
            i--;
        }
        return p;
    }

    void delete_X_recursion(int x, LNode * &p) {
        LNode * p2 = p;
        LNode *temp = nullptr;
        if (p == nullptr) {
            return;
        }
        if (p->data == x) {
            temp = p;
            p = p->next;
            delete temp;
        } else {
            p2 = p2->next;
        }
        return delete_X_recursion(x, p);
    }

};
