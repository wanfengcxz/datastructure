//
// Created by 晚风吹行舟 on 2021/6/13.
//

#include "MGraph.h"

void MGraph::createEmptyGraph(int vex_num_, VertexType *vex_) {
    // 初始化顶点信息
    vex = new VertexType[vex_num_];
    if (vex_ == nullptr) {
        for (int i = 0; i < vex_num_; i++)
            vex[i] = '1' + i;
    } else {
        for (int i = 0; i < vex_num_; i++)
            vex[i] = vex_[i];
    }
    vex_num = vex_num_;

    // 初始化边的信息
    edge = new EdgeType *[vex_num_];
    for (int i = 0; i < vex_num_; i++) {
        edge[i] = new EdgeType[vex_num_];
        for (int j = 0; j < vex_num_; j++)
            edge[i][j] = 0;
    }
}

void MGraph::addEdges(multimap<int, int> &edges_) {
    for (auto edge_:edges_) {
        edge[edge_.first - 1][edge_.second - 1] = 1;
        edge[edge_.second - 1][edge_.first - 1] = 1;
    }
    arc_num = edges_.size();
}

/**
 * 获取一个图的样例
 * @样例1
 *  1 —— 2    3 —— 4
 *  |    | /  | /  |
 *  5    6 —— 7 —— 8
 */
void MGraph::getInstance(int number) {

    if (number == 1) {
        createEmptyGraph(8);
        // 给边进行赋值
        multimap<int, int> edges = {{1, 2},
                                    {1, 5},
                                    {2, 6},
                                    {3, 6},
                                    {6, 7},
                                    {3, 7},
                                    {3, 4},
                                    {4, 8},
                                    {7, 4},
                                    {7, 8}};
        addEdges(edges);
    }

}

int MGraph::index(VertexType vex) {
    for (int i = 0; i < vex_num; i++) {
        if (this->vex[i] == vex)
            return i;
    }
    return -1;
}

vector<int> MGraph::neighbor(int vex_index) {
    vector<int> res;
    for (int i = 0; i < vex_num; i++) {
        if (edge[vex_index][i] != 0)
            res.push_back(i);
    }
    return res;
}

void MGraph::BFS_(int vex_index, bool *visited, vector<VertexType> &res) {
    // 辅助队列
    queue<int> q;
    q.push(vex_index);
    // 邻接节点列表
    vector<int> neighbor;

    // 将起始节点设置为已访问
    visited[vex_index] = true;
    res.emplace_back(vex[vex_index]);

    while (!q.empty()) {
        neighbor.clear();
        int curr = q.front();
        q.pop();

        // 获取当前节点的邻接节点
        neighbor = this->neighbor(curr);
        for (int i = 0; i < neighbor.size(); i++) {
            // 如果当前节点没有被访问过
            if (!visited[neighbor[i]]) {
                // 将当前节点加入访问序列中
                res.emplace_back(vex[neighbor[i]]);
                visited[neighbor[i]] = true;
                // 将当前邻接节点入队
                q.push(neighbor[i]);
            }
        }
    }
}

vector<VertexType> MGraph::BFS(VertexType vex_) {
    // 初始化visited数组 避免重复访问
    bool *visited = new bool[vex_num];
    for (int i = 0; i < vex_num; i++)
        visited[i] = false;

    // 遍历序列
    vector<VertexType> res;

    // 从vex_开始广度优先遍历
    BFS_(index(vex_), visited, res);

    // 处理非连通图
    for (int i = 0; i < vex_num; i++) {
        if (!visited[i]) {
            visited[i] = true;
            res.emplace_back(vex[i]);
            this->BFS_(i, visited, res);

        }
    }

    return res;
}

void MGraph::DFS_(int vex_index, bool *visited, vector<VertexType> &res) {

    visited[vex_index] = true;
    res.emplace_back(vex[vex_index]);
    // 获取当前节点的邻居节点
    vector<int> neighbor = this->neighbor(vex_index);

    for (int i = 0;i<neighbor.size();i++){
        if (!visited[neighbor[i]]){
            DFS_(neighbor[i], visited, res);
        }
    }
}

vector<VertexType> MGraph::DFS(VertexType vex_) {

    // 初始化visited数组 防止节点重复访问
    bool *visited = new bool[vex_num];
    for (int i = 0; i < vex_num; i++)
        visited[i] = false;

    // 遍历结果
    vector<VertexType> res;

    DFS_(index(vex_), visited, res);

    for (int i = 0; i < vex_num; i++) {
        if (!visited[i]) {
            visited[i] = true;
            res.emplace_back(vex[i]);
            DFS_(i, visited,res);
        }
    }
    return res;
}





