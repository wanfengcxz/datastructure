//
// Created by 晚风吹行舟 on 2021/5/21.
//
#include "BST.h"
#include "BST.cpp"
#include "gtest/gtest.h"


class BSTTest : public ::testing::Test {
protected:
    BST<int> bst;
    vector<int> init_data = {5, 4, 1, 2, 6, 8};
    vector<int> res;

protected:

    virtual void SetUp() {
        /**
         *      5
         *   4     6
         * 1         8
         *   2
         */
        bst.createBST(init_data);
    }

    virtual void TearDown() {

    }

};

TEST_F(BSTTest, createBST) {
    bst.inorderTraversal(res);
    ASSERT_EQ(bst.head()->data, 5);
    ASSERT_EQ(bst.head()->lchild->data, 4);
    ASSERT_EQ(bst.head()->rchild->data, 6);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 5);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 8);
    res.clear();
    bst.preorderTraversal(res);
    ASSERT_EQ(res[0], 5);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 2);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 8);
}

/**
*      5
*   4     6
* 1         8
*   2
*/
TEST_F(BSTTest, search) {
    ASSERT_EQ(bst.search(4)->data, 4);
    ASSERT_EQ(bst.search(3), nullptr);
    ASSERT_EQ(bst.search(2)->data, 2);

}

/**
*       5
*    4     6
*  1         8
*0   2     7
*/
TEST_F(BSTTest, insertNode) {
    ASSERT_EQ(bst.insertNode(0), 1);
    ASSERT_EQ(bst.insertNode(1), 0);
    ASSERT_EQ(bst.insertNode(7), 1);
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 0);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 2);
    ASSERT_EQ(res[3], 4);
    ASSERT_EQ(res[4], 5);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 7);
    ASSERT_EQ(res[7], 8);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res[0], 0);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 4);
    ASSERT_EQ(res[4], 7);
    ASSERT_EQ(res[5], 8);
    ASSERT_EQ(res[6], 6);
    ASSERT_EQ(res[7], 5);
}

/**
*      5
*   4     6
* 1         8
*   2
*/
TEST_F(BSTTest, getParent) {
    ASSERT_EQ(bst.getParent(1)->data,4);
    ASSERT_EQ(bst.getParent(2)->data,1);
    ASSERT_EQ(bst.getParent(8)->data,6);
}

/**
*      5
*   4     6
* 1         8
*   2
*/
TEST_F(BSTTest, deleteNode) {
    // 左子树不为空
    bst.deleteNode(4);
    ASSERT_EQ(bst.deleteNode(4), true);
    /**
    *      5
    *   1     6
    *     2     8
    */
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 5);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 8);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 8);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 5);

    // 右子树不为空
    bst.insertNode(13);
    bst.insertNode(7);
    bst.deleteNode(6);
    /**
    *      5
    *   1      8
    *     2  7  13
    */
    res.clear();
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 5);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 8);
    ASSERT_EQ(res[5], 13);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 7);
    ASSERT_EQ(res[3], 13);
    ASSERT_EQ(res[4], 8);
    ASSERT_EQ(res[5], 5);

    // 左右子树都为空
    bst.deleteNode(13);
    /**
    *      5
    *   1      8
    *     2  7
    */
    res.clear();
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 5);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 8);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 7);
    ASSERT_EQ(res[3], 8);
    ASSERT_EQ(res[4], 5);

    // 左右子树都不为空
    bst.insertNode(6);
    bst.insertNode(15);
    bst.insertNode(10);
    bst.insertNode(20);
    /**
    *       5
    *   1        8
    *     2    7   15
    *        6   10  20
    */
    bst.deleteNode(8);
    /**
    *       5
    *   1        15
    *     2    10  20
    *         7
    *        6
    */
    res.clear();
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 5);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 7);
    ASSERT_EQ(res[5], 10);
    ASSERT_EQ(res[6], 15);
    ASSERT_EQ(res[7], 20);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res.size(), 8);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 10);
    ASSERT_EQ(res[5], 20);
    ASSERT_EQ(res[6], 15);
    ASSERT_EQ(res[7], 5);

    // 删除根节点
    bst.deleteNode(5);
    /**
    *            15
    *          10  20
    *         7
    *        6
    *      1
    *        2
    */
    res.clear();
    bst.inorderTraversal(res);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 10);
    ASSERT_EQ(res[5], 15);
    ASSERT_EQ(res[6], 20);
    res.clear();
    bst.postorderTraversal(res);
    ASSERT_EQ(res.size(), 7);
    ASSERT_EQ(res[0], 2);
    ASSERT_EQ(res[1], 1);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 10);
    ASSERT_EQ(res[5], 20);
    ASSERT_EQ(res[6], 15);
}

/**
*      5
*   4     6
* 1         8
*   2
*/
TEST_F(BSTTest, isExist){
    ASSERT_EQ(bst.isExist(4), true);
    ASSERT_EQ(bst.isExist(8),true);
    ASSERT_EQ(bst.isExist(0),false);
    ASSERT_EQ(bst.isExist(13),false);
}

int main() {

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}
