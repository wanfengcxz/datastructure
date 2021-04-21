//
// Created by 晚风吹行舟 on 2021/4/20.
//
#include "gtest/gtest.h"
#include "StaticLinkedList.h"
#include "StaticLinkedList.cpp"


class StaticLinkedListTest : public ::testing::Test {
protected:
    StaticLinkedList staticLinkedList;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }
};




int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
