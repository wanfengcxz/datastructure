//
// Created by 晚风吹行舟 on 2021/5/7.
//
#include "gtest/gtest.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"

/**
*      1
*   2     3
*  4     6  7
*/

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<int> bt1,bt2,bt3,bt4;
    vector<int> res;

protected:
    virtual void SetUp() {
        bt1.initBinaryTree();
        // 此树结构见img/bt2.png
        bt2.deserialize("[1,2,3,4,null,6,7,8,null,12,null,14,15]");
    }

    virtual void TearDown() {

    }
};

TEST_F(BinaryTreeTest, height){
    ASSERT_EQ(bt1.height(), 3);
    ASSERT_EQ(bt2.height(), 4);
}


TEST_F(BinaryTreeTest, preorderTraversalRecur) {
    bt1.preorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 3);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.preorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 8);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 12);
    ASSERT_EQ(res[7], 7);
    ASSERT_EQ(res[8], 14);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, inorderTraversalRecur) {
    bt1.inorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.inorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 8);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2], 2);
    ASSERT_EQ(res[3], 1);
    ASSERT_EQ(res[4], 12);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 3);
    ASSERT_EQ(res[7], 14);
    ASSERT_EQ(res[8], 7);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, postorderTraversalRecur) {
    bt1.postorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 1);
    res.clear();
    bt2.postorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 8);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2],2);
    ASSERT_EQ(res[3], 12);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 14);
    ASSERT_EQ(res[6], 15);
    ASSERT_EQ(res[7], 7);
    ASSERT_EQ(res[8], 3);
    ASSERT_EQ(res[9], 1);
}

TEST_F(BinaryTreeTest, preorderTraversal){
    bt1.preorderTraversal(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 3);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.preorderTraversal(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 8);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 12);
    ASSERT_EQ(res[7], 7);
    ASSERT_EQ(res[8], 14);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, inorderTraversal){
    bt1.inorderTraversal(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.inorderTraversal(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 8);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2], 2);
    ASSERT_EQ(res[3], 1);
    ASSERT_EQ(res[4], 12);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 3);
    ASSERT_EQ(res[7], 14);
    ASSERT_EQ(res[8], 7);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, postorderTraversal){
    bt1.postorderTraversal(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 1);
    res.clear();
    bt2.postorderTraversal(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 8);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2],2);
    ASSERT_EQ(res[3], 12);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 14);
    ASSERT_EQ(res[6], 15);
    ASSERT_EQ(res[7], 7);
    ASSERT_EQ(res[8], 3);
    ASSERT_EQ(res[9], 1);
}

TEST_F(BinaryTreeTest, levelTraversal){
    bt1.levelTraversal(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 3);
    ASSERT_EQ(res[3], 4);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.levelTraversal(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2],3);
    ASSERT_EQ(res[3], 4);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 7);
    ASSERT_EQ(res[6], 8);
    ASSERT_EQ(res[7], 12);
    ASSERT_EQ(res[8], 14);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, serialize){
    ASSERT_STREQ(bt1.serialize().c_str(), "[1,2,3,4,null,6,7]");
    ASSERT_STREQ(bt2.serialize().c_str(), "[1,2,3,4,null,6,7,8,null,12,null,14,15]");
}

TEST_F(BinaryTreeTest, deserialize){
    bt3.deserialize("[20,12,354,15,null,26,null]");
    ASSERT_STREQ(bt3.serialize().c_str(), "[20,12,354,15,null,26,null]");
    bt4.deserialize("[1,2,3,4,5,6,null]");
    cout << bt4.serialize();
    ASSERT_STREQ(bt4.serialize().c_str(),"[1,2,3,4,5,6,null]");
}

TEST_F(BinaryTreeTest, inorderThread){
    bt1.inOrderThreading();
    bt1.inOrder(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 7);
    res.clear();
    bt2.inOrderThreading();
    bt2.inOrder(res);
    ASSERT_EQ(res.size(), 10);
    ASSERT_EQ(res[0], 8);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2], 2);
    ASSERT_EQ(res[3], 1);
    ASSERT_EQ(res[4], 12);
    ASSERT_EQ(res[5], 6);
    ASSERT_EQ(res[6], 3);
    ASSERT_EQ(res[7], 14);
    ASSERT_EQ(res[8], 7);
    ASSERT_EQ(res[9], 15);
}

TEST_F(BinaryTreeTest, FBT){
    ASSERT_EQ(bt1.isFullBinaryTree(), false);
    ASSERT_EQ(bt1.isFullBinaryTree(), false);
    bt3.deserialize("[1,2,3,4,5,6]");
    ASSERT_EQ(bt3.isFullBinaryTree(), false);
    bt4.deserialize("[1,2,3,4,5,6,7]");
    ASSERT_EQ(bt4.isFullBinaryTree(), true);

}

TEST_F(BinaryTreeTest, CBT){
    ASSERT_EQ(bt1.isCompleteBinaryTree(), false);
    ASSERT_EQ(bt2.isCompleteBinaryTree(),false);
    bt3.deserialize("[1,2,3,4,5,6]");
    ASSERT_EQ(bt3.isCompleteBinaryTree(), true);
    bt4.deserialize("[1,2,3,4]");
    ASSERT_EQ(bt4.isCompleteBinaryTree(), true);
}

int main() {
//    BinaryTree<int> binaryTree;
//    vector<int> res;
//    binaryTree.initBinaryTree();
//    binaryTree.postorderTraversal(res);
//    cout << endl;

//    binaryTree.deserialize("[1,2,3,4,null,6,7,8,null,12,null,14,15]");
//    binaryTree.deserialize("[1,2,3,null,null,4,5]");
//    cout << binaryTree.serialize() << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}
