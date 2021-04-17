//
// Created by 晚风吹行舟 on 2021/4/17.
//
#pragma once

#include "SeqTable.cpp"
#include "gtest/gtest.h"
#include <stack>


class StaticSeqTableTest : public ::testing::Test {
protected:
    staticAllocation::SeqTable seq_table_static;
    staticAllocation::T e;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        seq_table_static.insertElement(1,1);
        seq_table_static.insertElement(2,2);
        seq_table_static.insertElement(3,3);
        seq_table_static.insertElement(4,4);
    }

};


TEST_F(StaticSeqTableTest, getLength) {
    ASSERT_EQ(seq_table_static.getLength(),4);
    ASSERT_EQ(seq_table_static.insertElement(6,6),false);
    ASSERT_EQ(seq_table_static.getLength(),4);
}

TEST_F(StaticSeqTableTest,insertElement){
    ASSERT_EQ(seq_table_static.insertElement(6,6), false);
    ASSERT_EQ(seq_table_static.insertElement(1,10),true);
    ASSERT_EQ(seq_table_static.insertElement(6,6),true);
}

TEST_F(StaticSeqTableTest, locateElement){
    ASSERT_EQ(seq_table_static.insertElement(1,10),true);
    ASSERT_EQ(seq_table_static.insertElement(6,6),true);
    ASSERT_EQ(seq_table_static.locateElement(20),0);
    ASSERT_EQ(seq_table_static.locateElement(10),1);
    ASSERT_EQ(seq_table_static.locateElement(1),2);
    ASSERT_EQ(seq_table_static.locateElement(2),3);
    ASSERT_EQ(seq_table_static.locateElement(3),4);
    ASSERT_EQ(seq_table_static.locateElement(6),6);
}

TEST_F(StaticSeqTableTest, deleteElement){
    ASSERT_EQ(seq_table_static.deleteElement(1,e),true);
    ASSERT_EQ(seq_table_static.deleteElement(4,e), false);
}


class DynamicSeqTableTest : public ::testing::Test {

protected:
    dynamicAllocation::SeqTable seq_table_dynamic;
    dynamicAllocation::T e;

protected:
    virtual void TearDown() {


    }

    virtual void SetUp() {
        seq_table_dynamic.insertElement(1,1);
        seq_table_dynamic.insertElement(2,2);
    }

};


TEST_F(DynamicSeqTableTest, capacity) {
    ASSERT_EQ(seq_table_dynamic.getCapacity(),2);
    ASSERT_EQ(seq_table_dynamic.size(),2);
    ASSERT_EQ(seq_table_dynamic.insertElement(3,3),true);
    ASSERT_EQ(seq_table_dynamic.getCapacity(),4);
    ASSERT_EQ(seq_table_dynamic.size(),3);
    ASSERT_EQ(seq_table_dynamic.insertElement(3,4),true);
    ASSERT_EQ(seq_table_dynamic.getCapacity(),4);
    ASSERT_EQ(seq_table_dynamic.size(),4);
    ASSERT_EQ(seq_table_dynamic.insertElement(5,5),true);
    ASSERT_EQ(seq_table_dynamic.getCapacity(),8);
    ASSERT_EQ(seq_table_dynamic.size(),5);
    for (int i = 0;i<6;i++){
        seq_table_dynamic.insertElement(1,i);
    }
    ASSERT_EQ(seq_table_dynamic.getCapacity(),16);
}

TEST_F(DynamicSeqTableTest, insertElement){
    ASSERT_EQ(seq_table_dynamic.insertElement(8,8),false);
    ASSERT_EQ(seq_table_dynamic.insertElement(3,3),true);
    ASSERT_EQ(seq_table_dynamic.insertElement(1,10),true);
}


TEST_F(DynamicSeqTableTest, locateElement) {
    ASSERT_EQ(seq_table_dynamic.locateElement(2),2);
    ASSERT_EQ(seq_table_dynamic.insertElement(3,5),true);
    ASSERT_EQ(seq_table_dynamic.locateElement(5),3);
}

TEST_F(DynamicSeqTableTest, deleteElement){
    ASSERT_EQ(seq_table_dynamic.deleteElement(1,e),true);
    ASSERT_EQ(seq_table_dynamic.insertElement(2,2),true);
    ASSERT_EQ(seq_table_dynamic.insertElement(3,3),true);
    ASSERT_EQ(seq_table_dynamic.deleteElement(5,e),false);
    ASSERT_EQ(seq_table_dynamic.deleteElement(3,e),true);
    ASSERT_EQ(e,3);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}




