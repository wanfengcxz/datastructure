//
// Created by 晚风吹行舟 on 2021/6/13.
//
#include "gtest/gtest.h"
#include "MGraph.h"
#include "MGraph.cpp"

class MGraphTest : public ::testing::Test {
protected:
    MGraph graph1, graph2;
    vector<VertexType> res;

protected:
    virtual void SetUp() {
        graph1.getInstance(1);
//        graph2.getInstance(2);

    }

};

/**
 *  1 —— 2    3 —— 4
 *  |    | /  | /  |
 *  5    6 —— 7 —— 8
 */
TEST_F(MGraphTest, BFS) {
    ASSERT_EQ(graph1.vexNum(), 8);
    ASSERT_EQ(graph1.edgeNum(), 10);
    res = graph1.BFS('2');
    ASSERT_EQ(res[0], '2');
    ASSERT_EQ(res[1], '1');
    ASSERT_EQ(res[2], '6');
    ASSERT_EQ(res[3], '5');
    ASSERT_EQ(res[4], '3');
    ASSERT_EQ(res[5], '7');
    ASSERT_EQ(res[6], '4');
    ASSERT_EQ(res[7], '8');
    res.clear();
    res = graph1.BFS('6');
    ASSERT_EQ(res[0], '6');
    ASSERT_EQ(res[1], '2');
    ASSERT_EQ(res[2], '3');
    ASSERT_EQ(res[3], '7');
    ASSERT_EQ(res[4], '1');
    ASSERT_EQ(res[5], '4');
    ASSERT_EQ(res[6], '8');
    ASSERT_EQ(res[7], '5');

}

/**
 *  1 —— 2    3 —— 4
 *  |    | /  | /  |
 *  5    6 —— 7 —— 8
 */
TEST_F(MGraphTest, DFS) {
    ASSERT_EQ(graph1.vexNum(), 8);
    ASSERT_EQ(graph1.edgeNum(), 10);
    res = graph1.DFS('3');
    ASSERT_EQ(res[0], '3');
    ASSERT_EQ(res[1], '4');
    ASSERT_EQ(res[2], '7');
    ASSERT_EQ(res[3], '6');
    ASSERT_EQ(res[4], '2');
    ASSERT_EQ(res[5], '1');
    ASSERT_EQ(res[6], '5');
    ASSERT_EQ(res[7], '8');
    res.clear();
    res = graph1.DFS('1');
    ASSERT_EQ(res[0], '1');
    ASSERT_EQ(res[1], '2');
    ASSERT_EQ(res[2], '6');
    ASSERT_EQ(res[3], '3');
    ASSERT_EQ(res[4], '4');
    ASSERT_EQ(res[5], '7');
    ASSERT_EQ(res[6], '8');
    ASSERT_EQ(res[7], '5');
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}
