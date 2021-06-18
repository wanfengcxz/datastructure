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

void MGraph::addEdges(multimap<int, int> &edges_, bool isDirected) {
    // 无向图
    if (!isDirected) {
        for (auto edge_:edges_) {
            edge[edge_.first - 1][edge_.second - 1] = 1;
            edge[edge_.second - 1][edge_.first - 1] = 1;
        }
        // 有向图
    } else {
        for (auto edge_:edges_)
            edge[edge_.first - 1][edge_.second - 1] = 1;
    }
    arc_num = edges_.size();
}


void MGraph::getInstance(int number) {

    if (number == 1) {
        /**
         * 获取一个图的样例
         * @样例1
         *  1 —— 2    3 —— 4
         *  |    | /  | /  |
         *  5    6 —— 7 —— 8
         */
        // DFS BFS test case
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
        addEdges(edges, false);
        /**
        * 获取一个图的样例
        * @样例2
        *  1 ——→ 2 ——→  4
        *           ↗   ↓
        *        3 ——→  5
        */
    } else if (number == 2) {
        // 拓扑排序 test case
        createEmptyGraph(5);
        // 给边赋值
        multimap<int, int> edges = {{1, 2},
                                    {2, 4},
                                    {3, 4},
                                    {3, 5},
                                    {4, 5}};
        addEdges(edges, true);
    } else if (number == 3) {
        // 最小生成树 prim kruskal
        createEmptyGraph(6);
        // 给边赋值
        edge[0][1] = 6;
        edge[0][2] = 5;
        edge[0][3] = 1;
        edge[1][0] = 6;
        edge[2][0] = 5;
        edge[3][0] = 1;
        edge[3][1] = 5;
        edge[3][2] = 4;
        edge[3][4] = 6;
        edge[3][5] = 4;
        edge[1][3] = 5;
        edge[2][3] = 4;
        edge[4][3] = 6;
        edge[5][3] = 4;
        edge[1][4] = 3;
        edge[4][1] = 3;
        edge[4][5] = 6;
        edge[5][4] = 6;
        edge[5][2] = 2;
        edge[2][5] = 2;
        arc_num = 10;
    }
}

int MGraph::index(VertexType vex_) {
    for (int i = 0; i < vex_num; i++) {
        if (this->vex[i] == vex_)
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

    for (int i = 0; i < neighbor.size(); i++) {
        if (!visited[neighbor[i]]) {
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
            DFS_(i, visited, res);
        }
    }
    return res;
}


vector<int> MGraph::prim(VertexType vex_) {
    return vector<int>();
}

int getRoot(int node_index, vector<int> &v) {
    while (node_index != v[node_index]) node_index = v[node_index];
    return node_index;
}

vector<int> MGraph::kruskal() {

    // 构造权值边表
    vector<Edge> min_weight_vec;
    for (int i = 0; i < vex_num; i++) {
        for (int j = i + 1; j < vex_num; j++) {
            if (edge[i][j] != 0) {
                min_weight_vec.emplace_back(Edge(i, j, edge[i][j]));
            }
        }
    }

    // 初始化并查集数组
    vector<int> v(vex_num, 0);
    for (int i = 0; i < vex_num; i++)
        v[i] = i;

    // 按权值递增排序
    sort(min_weight_vec.begin(), min_weight_vec.end());

    // 构成最小生成树的边的权值
    vector<int> res;

    int root_start = 0, root_end = 0;
    for (int i = 0; i < min_weight_vec.size(); i++) {
        root_start = getRoot(min_weight_vec[i].start, v);
        root_end = getRoot(min_weight_vec[i].end, v);
        if (root_start != root_end) {
            v[root_start] = root_end;
            res.push_back(min_weight_vec[i].weight);
        }
    }

    return res;
}

vector<VertexType> MGraph::reverseTopologicalSort() {

    int *indegree = new int[vex_num];


    return vector<VertexType>();
}

vector<VertexType> MGraph::topologicalSort() {
    // 输出序列
    vector<VertexType> res(vex_num, 'a');
    queue<int> q;
    // 邻接顶点
    vector<int> neighbor;

    // 统计各个顶点的入度
    int *indegree = new int[this->vex_num];
    for (int i = 0; i < vex_num; i++) {
        indegree[i] = 0;
        for (int j = 0; j < vex_num; j++)
            if (edge[j][i] != 0)
                indegree[i]++;
    }

    // 将度为0的顶点入栈
    for (int i = 0; i < vex_num; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // 统计已排序的顶点的个数
    int count = 0;
    // 栈不为空
    while (!q.empty()) {
        neighbor.clear();
        int index = q.front();
        q.pop();
        res[count++] = vex[index];
        neighbor = this->neighbor(index);
        for (int i = 0; i < neighbor.size(); i++) {
            if (--indegree[neighbor[i]] == 0)
                q.push(neighbor[i]);
        }
    }
    if (count < vex_num)
        return vector<VertexType>();
    else
        return res;
}






