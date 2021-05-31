//
// Created by 晚风吹行舟 on 2021/5/21.
//

#ifndef DATASTRUCTURE_BST_H
#define DATASTRUCTURE_BST_H

#include <vector>
#include "../BinaryTree/BinaryTree.h"
#include "../BinaryTree/BinaryTree.cpp"

using std::vector;

template<typename T>
class BST : public BinaryTree<T> {

public:

    explicit BST() : BinaryTree<T>() {}

    BiTNode<T> *search(T key);

    /**
     * 二叉搜索树的插入操作
     * @param key
     * @return 1 插入成功 0 插入失败
     */
    int insertNode(T key);

    /**
     * 通过数组创建二叉搜索树
     * @param arr 数组
     */
    void createBST(vector<T> arr);

public:
    /**
     * 删除某个节点，同时保持二叉搜索树的性质不变
     * 如果目标节点大于当前节点值，则去右子树中删除；
     * 如果目标节点小于当前节点值，则去左子树中删除；
     * 如果目标节点就是当前节点，分为以下三种情况：。。
     *    其无左子：其右子顶替其位置，删除了该节点；
     *    其无右子：其左子顶替其位置，删除了该节点；
     *    其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，
     *    然后右子树顶替其位置，由此删除了该节点。
     * @param key 值
     * @return 删除是否成功
     */
    bool deleteNode(T key);

    /**
     * 获取当前节点的双亲节点
     * @param key 值
     * @return 指向双亲节点的指针
     */
    BiTNode<T> *getParent(T key);

    bool isExist(T key);

};


#endif //DATASTRUCTURE_BST_H
