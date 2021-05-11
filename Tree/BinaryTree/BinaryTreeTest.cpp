//
// Created by 晚风吹行舟 on 2021/5/7.
//
#include "gtest/gtest.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<int> binaryTree;
    vector<int> res;

protected:
    virtual void SetUp() {
        binaryTree.initBinaryTree();
//        res.clear();
    }

    virtual void TearDown() {

    }
};

TEST_F(BinaryTreeTest, preorderTraversalRecur) {
    binaryTree.preorderTraversalRecur(res);
    ASSERT_EQ(res.size(), 6);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 4);
    ASSERT_EQ(res[3], 3);
    ASSERT_EQ(res[4], 6);
    ASSERT_EQ(res[5], 7);



}

TEST_F(BinaryTreeTest, postorderTraversalRecur) {
    binaryTree.postorderTraversalRecur(res);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 6);
    ASSERT_EQ(res[3], 7);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 1);
}

TEST_F(BinaryTreeTest, inorderTraversalRecur) {
    binaryTree.inorderTraversalRecur(res);
    ASSERT_EQ(res[0], 4);
    ASSERT_EQ(res[1], 2);
    ASSERT_EQ(res[2], 1);
    ASSERT_EQ(res[3], 6);
    ASSERT_EQ(res[4], 3);
    ASSERT_EQ(res[5], 7);
}

int main() {

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}
