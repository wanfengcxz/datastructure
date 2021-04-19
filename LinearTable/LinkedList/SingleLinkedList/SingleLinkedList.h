//
// Created by 晚风吹行舟 on 2021/4/17.
//

#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include "../LNode.h"

// 含有头节点
class SingleLinkedList {

private:
    // 头指针
    LNode *head;

private:

    /**
    * 头插法 一次只插入单个数据
    * @param data
    */
    inline void headInsert(T data){
        LNode *temp = new LNode(data);
        temp->next = head->next;
        head->next = temp;
        head->data++;
    }

public:

    /**
     * 初始化头节点
     */
    SingleLinkedList():head(new LNode(0)) {
        // head->data is length
    }

    /**
     * 头插法 从数组构建链表
     * @param data
     * @param len
     */
    void headInsert(T data[], int len);

    /**
     * 尾插法 从数组构建链表
     * @param data
     * @param len
     */
    void tailInsert(T data[], int len);

    /**
     * 获取链表长度
     * @return length
     */
    int length(){
        return head->data;
    }

    /**
     * 获取指定位置的节点
     * @param i
     * @return 节点指针/nullptr
     */
    LNode *getElem(int i);

    /**
     * 按值查找
     * @param e
     * @return 节点指针/nullptr
     */
    LNode *locateElem(T e);

    /**
     * 在第i个节点处插入一个节点 前插操作
     * @param i index
     * @param e value
     * @return 插入是否成功
     */
    bool insertElem(int i, T e);

    /**
     * 在第i个节点处插入一个节点 后插操作
     * 使用一个匿名参数与前插操作区别开来
     * @param i index
     * @param e value
     * @return 插入是否成功
     */
     bool insertElem(int i, T e, int);

     /**
      * 删除第i个节点
      * @param i index
      * @param e 删除的值
      * @return 删除是否成功
      */
     bool deleteElem(int i, T &e);

};

#endif //DATASTRUCTURE_SINGLELINKEDLIST_H
