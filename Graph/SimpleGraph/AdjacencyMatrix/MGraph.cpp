//
// Created by 晚风吹行舟 on 2021/6/13.
//

#include "MGraph.h"

void MGraph::createEmptyGraph(int vex_num_, VertexType *vex_, int defaultINF) {
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
                // 无穷大表示方法默认为0 也可以传参来控制
                edge[i][j] = defaultINF;
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
        * 获取一个图的样例 有向图
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
        // 无向带权图
        // 最小生成树 prim kruskal
        // img/graph1.png
        createEmptyGraph(6, nullptr, INF);
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
    } else if (number == 4){
        // Dijkstra 有向带权图
        // img/graph2.png
        createEmptyGraph(5, nullptr, INF);
        // 给边赋值
        edge[0][1] = 10;
        edge[1][2] = 1;
        edge[0][4] = 5;
        edge[1][4] = 2;
        edge[4][1] = 3;
        edge[4][2] = 9;
        edge[3][0] = 7;
        edge[4][3] = 2;
        edge[2][3] = 4;
        edge[3][2] = 6;
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

vector<int> MGraph::Prim(VertexType vex_) {

    // 标记各节点是否加入最小生成树
    bool *isJoined = new bool[vex_num];
    // 各节点加入最小生成树的最小代价
    int *lowCost = new int[vex_num];
    // 加入到最小生成树的边
    vector<int> res;
    // 起始顶点的下标
    int start_vex_index = this->index(vex_);

    // 初始化
    for (int i = 0;i<vex_num;i++){
        isJoined[i] = false;
        lowCost[i] = edge[start_vex_index][i];
    }
    // 起始节点默认被加入最小生成树
    isJoined[start_vex_index] = true;

    // 当前还有vex_num-1个节点没有被加入最小生成树
    // 所以循环vex_num-1次
    for (int i = 0;i<vex_num-1;i++){
        // 保存代价最小的节点的代价值和下标
        int min = INF;
        int min_index;
        // 找出代价最小的节点
        for (int j = 0;j<vex_num;j++){
            if (!isJoined[j] && lowCost[j] < min){
                min = lowCost[j];
                min_index = j;
            }
        }
        // 将当前最小代价的节点加入最小生成树
        isJoined[min_index] = true;
        // 将此边加入最小生成树的边集
        res.push_back(min);

        // 更新各个节点的最小代价
        for (int j = 0;j<vex_num;j++){
            if (!isJoined[j] && lowCost[j] > edge[min_index][j])
                lowCost[j] = edge[min_index][j];
        }
    }
    return res;
}

int getRoot(int node_index, vector<int> &v) {
    while (node_index != v[node_index]) node_index = v[node_index];
    return node_index;
}

vector<int> MGraph::Kruskal() {

    // 构造权值边表
    vector<Edge> min_weight_vec;
    for (int i = 0; i < vex_num; i++) {
        for (int j = i + 1; j < vex_num; j++) {
            if (edge[i][j] != INF) {
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

ShortestPath* MGraph::Dijkstra(VertexType vex_) {

    // 保存各个顶点是否找到最短路径，最短路径长度和路径上的前驱节点
    ShortestPath *shortestPath = new ShortestPath[vex_num];

    // 初始化
    int start_node_index = this->index(vex_);
    for (int i = 0;i<vex_num;i++){
        shortestPath[i].isFind = false;
        shortestPath[i].dist = edge[start_node_index][i];
        if (shortestPath[i].dist == INF)
            shortestPath[i].predecessor = -1;
        else
            shortestPath[i].predecessor = start_node_index;
    }

    // 起始节点已经找到最短路径
    shortestPath[start_node_index].dist = 0;
    shortestPath[start_node_index].isFind = true;

    // 当前还有vex_num-1个顶点没有找到最短路径
    for (int i = 0;i<vex_num-1;i++){
        int min = INF, min_index;
        for (int j = 0;j<vex_num;j++){
            if (shortestPath[j].isFind == false && min > shortestPath[j].dist){
                min = shortestPath[j].dist;
                min_index = j;
            }
        }
        // 此顶点已找到最短路径
        shortestPath[min_index].isFind = true;
        // 更新起始点到其他顶点的路径值
        for (int j = 0;j<vex_num;j++){
            if (shortestPath[j].isFind == false && shortestPath[j].dist > min+edge[min_index][j]){
                shortestPath[j].dist = min+edge[min_index][j];
                shortestPath[j].predecessor = min_index;
            }
        }
    }

    return shortestPath;
}


vector<VertexType> MGraph::reverseTopologicalSort() {

    // 逆拓扑序列排序结果
    vector<VertexType> res;
    queue<int> q;

    // 各个顶点的出度表
    int *outdegree = new int[vex_num];
    // 初始化
    for (int i = 0;i<vex_num;i++){
        outdegree[i] = 0;
        for (int j = 0;j<vex_num;j++){
            if (edge[i][j] != 0)
                outdegree[i]++;
        }
    }

    // 将出度为0的顶点加入栈
    for (int i = 0;i<vex_num;i++){
        if (outdegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        // 取出队头元素
        int curr = q.front();
        q.pop();
        // 将队头元素对应的顶点加入结果集
        res.push_back(vex[curr]);

        // 更新以当前顶点作为后继顶点的顶点的出度
        for (int i = 0;i<vex_num;i++){
            if (edge[i][curr] != 0){
                // 出度减一
                outdegree[i]--;
                // 出度减一后如果为0，则加入队列
                if (outdegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }

    return res;
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







