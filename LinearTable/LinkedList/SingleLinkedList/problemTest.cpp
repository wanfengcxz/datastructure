//
// Created by 晚风吹行舟 on 2021/4/23.
//
#include "gtest/gtest.h"
#include "problem.cpp"


class SingleLListTest : public ::testing::Test {

protected:
    SingleLList singleLinkedList;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        int arr[4] = {1,2,3,2};
        singleLinkedList.headInsert(arr, 4);
    }

};


TEST_F(SingleLListTest, getElem) {
    ASSERT_EQ(singleLinkedList.getElem(1)->data,2);
    ASSERT_EQ(singleLinkedList.getElem(2)->data,3);
    ASSERT_EQ(singleLinkedList.getElem(3)->data,2);
    ASSERT_EQ(singleLinkedList.getElem(4)->data,1);
}

TEST_F(SingleLListTest, delete_X_recursion){
    LNode * head = singleLinkedList.getElem(1);
    singleLinkedList.delete_X_recursion(2, head);
    ASSERT_EQ(singleLinkedList.getElem(1)->data,3);
    ASSERT_EQ(singleLinkedList.getElem(2)->data, 1);


}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
