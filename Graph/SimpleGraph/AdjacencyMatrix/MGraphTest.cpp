//
// Created by 晚风吹行舟 on 2021/6/13.
//
#include "gtest/gtest.h"
#include "MGraph.h"
#include "MGraph.cpp"

class MGraphTest : public ::testing::Test {
protected:
    MGraph graph1;
    vector<VertexType> res;

};

/**
 *  1 —— 2    3 —— 4
 *  |    | /  | /  |
 *  5    6 —— 7 —— 8
 */
TEST_F(MGraphTest, BFS) {
    graph1.getInstance(1);
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
    graph1.getInstance(1);
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

// img/graph1.png
TEST_F(MGraphTest, Prim){
    vector<int> res;
    graph1.getInstance(3);
    res = graph1.Prim('1');
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], 1);
    ASSERT_EQ(res[1], 4);
    ASSERT_EQ(res[2], 2);
    ASSERT_EQ(res[3], 5);
    ASSERT_EQ(res[4], 3);

}

// img/graph1.png
TEST_F(MGraphTest, Kruskal) {
    vector<int> res;
    graph1.getInstance(3);
    ASSERT_EQ(graph1.vexNum(), 6);
    ASSERT_EQ(graph1.edgeNum(), 10);
    res = graph1.Kruskal();
    ASSERT_EQ(res.size(), 5);
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(res[i], i + 1);
    }
}

// img/graph2.png
TEST_F(MGraphTest, Dijkstra) {
    ShortestPath *shortestPath;
    graph1.getInstance(4);
    ASSERT_EQ(graph1.vexNum(), 5);
    ASSERT_EQ(graph1.edgeNum(), 10);
    shortestPath = graph1.Dijkstra('1');
    ASSERT_EQ(shortestPath[0].dist, 0);
    ASSERT_EQ(shortestPath[0].predecessor, -1);
    ASSERT_EQ(shortestPath[0].isFind, true);

    ASSERT_EQ(shortestPath[1].dist, 8);
    ASSERT_EQ(shortestPath[1].predecessor, 4);
    ASSERT_EQ(shortestPath[1].isFind, true);

    ASSERT_EQ(shortestPath[2].dist, 9);
    ASSERT_EQ(shortestPath[2].predecessor, 1);
    ASSERT_EQ(shortestPath[2].isFind, true);

    ASSERT_EQ(shortestPath[3].dist, 7);
    ASSERT_EQ(shortestPath[3].predecessor, 4);
    ASSERT_EQ(shortestPath[3].isFind, true);

    ASSERT_EQ(shortestPath[4].dist, 5);
    ASSERT_EQ(shortestPath[4].predecessor, 0);
    ASSERT_EQ(shortestPath[4].isFind, true);

}

/**
    *  1 ——→ 2 ——→  4
    *           ↗   ↓
    *        3 ——→  5
    */
TEST_F(MGraphTest, topologicalSort) {
    graph1.getInstance(2);
    ASSERT_EQ(graph1.vexNum(), 5);
    ASSERT_EQ(graph1.edgeNum(), 5);
    res = graph1.topologicalSort();
    ASSERT_EQ(res.size(), 5);
    ASSERT_EQ(res[0], '1');
    ASSERT_EQ(res[1], '3');
    ASSERT_EQ(res[2], '2');
    ASSERT_EQ(res[3], '4');
    ASSERT_EQ(res[4], '5');
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
}
