//
// Created by 晚风吹行舟 on 2021/4/17.
//
#include "SingleLinkedList.h"
#include "SingleLinkedList.cpp"
#include "gtest/gtest.h"

class SingleLinkedListTest : public ::testing::Test {

protected:
    SingleLinkedList singleLinkedList;
    int data[4] = {1, 2, 3, 4};
    T e = 0;

protected:
    virtual void SetUp() {
        singleLinkedList.headInsert(data, 4);
    }

    virtual void TearDown() {

    }

};

TEST_F(SingleLinkedListTest, locateElem) {
    ASSERT_EQ(singleLinkedList.length(), 4);
    ASSERT_EQ(singleLinkedList.locateElem(5), nullptr);
    ASSERT_EQ(singleLinkedList.locateElem(0), nullptr);
    ASSERT_EQ(singleLinkedList.locateElem(3)->data, 3);
}

TEST_F(SingleLinkedListTest, getElem) {
    ASSERT_EQ(singleLinkedList.getElem(2)->data, 3);
    ASSERT_EQ(singleLinkedList.getElem(1)->data, 4);
    ASSERT_EQ(singleLinkedList.getElem(0)->data, 4);
    ASSERT_EQ(singleLinkedList.getElem(5), nullptr);
}


TEST_F(SingleLinkedListTest, insertElement) {
    ASSERT_EQ(singleLinkedList.insertElem(1, 5), true);
    ASSERT_EQ(singleLinkedList.insertElem(1, 6, 0), true);
    ASSERT_EQ(singleLinkedList.insertElem(0, 5), false);
    ASSERT_EQ(singleLinkedList.insertElem(0, 5, 0), false);
    ASSERT_EQ(singleLinkedList.length(), 6);
//    singleLinkedList.insertElem(7, 0);
    ASSERT_EQ(singleLinkedList.insertElem(7, 0), true);
    ASSERT_EQ(singleLinkedList.insertElem(8, 0, 0), true);
    ASSERT_EQ(singleLinkedList.length(), 8);
    ASSERT_EQ(singleLinkedList.insertElem(10, 1), false);
    ASSERT_EQ(singleLinkedList.insertElem(10, 1, 0), false);
}

TEST_F(SingleLinkedListTest, tailInsert) {
    ASSERT_EQ(singleLinkedList.deleteElem(1, e), true);
    ASSERT_EQ(e, 4);
    ASSERT_EQ(singleLinkedList.length(), 3);
    ASSERT_EQ(singleLinkedList.deleteElem(5, e), false);
    ASSERT_EQ(singleLinkedList.deleteElem(2, e), true);
    ASSERT_EQ(singleLinkedList.deleteElem(1, e), true);
    ASSERT_EQ(singleLinkedList.deleteElem(1, e), true);
    singleLinkedList.tailInsert(data, 4);
    ASSERT_EQ(singleLinkedList.length(), 4);
    ASSERT_EQ(singleLinkedList.getElem(2)->data, 2);
    ASSERT_EQ(singleLinkedList.getElem(3)->data, 3);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


