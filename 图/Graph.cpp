//
// Created by yzm-dev on 2022/5/24.
//
#include <iostream>

using namespace std;
// 采用邻接表法实现图
const int MAXSIZE = 30; //顶点最多的个数
int dfsvisit[MAXSIZE]; //深度优先搜索全局数组,初始化全为0,判断图结点是否访问过
int bfsvisit[MAXSIZE]; //广度优先搜索全局数组,初始化全为0,判断图结点是否访问过

// 边结点定义
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc; //边指向下一条边
} ArcNode;

// 定点结点定义
typedef struct VexNode {
    int vex;
    ArcNode *firstarc; //顶点指向第一条边
} VexNode;

// 图的定义
typedef struct {
    int n, e; //顶点，边的个数
    VexNode vexarr[MAXSIZE];
} Graph;

// 邻接表创建图
void CreateGraph(Graph *&G) {
    G = new Graph; //申请图的空间
    for (int i = 0; i < MAXSIZE; ++i) {
        G->vexarr[i].vex = -1;
        G->vexarr[i].firstarc = nullptr;
    }
    cout << "输入结点个数, 边的条数(如: 5 7): ";
    cin >> G->n;
    cin >> G->e;
    VexNode *V;
    for (int i = 1; i <= G->n; ++i) {
        cout << "输入根节点值: ";
        V = &G->vexarr[i];
        cin >> V->vex;
        cout << "输入根节点连接的边结点值: ";
        int adjvex;
        cin >> adjvex;
        if (adjvex == -1) {// 根结点没有边结点
            V->firstarc = nullptr;
        } else {
            ArcNode *p = new ArcNode;
            ArcNode *r;// 尾指针，作标记
            p->adjvex = adjvex;
            V->firstarc = p;
            r = p;
            cin >> adjvex;
            while (adjvex != -1) {
                ArcNode *q = new ArcNode;
                q->adjvex = adjvex;
                r->nextarc = q;
                r = q;//r始终指向链尾
                cin >> adjvex;
            }
            r->nextarc = nullptr;//链尾指空
        }
    }
}

// 查看结点的值
void Visit(Graph *G, int v) {
    if (v <= G->n) { //根结点存在则访问
        cout << G->vexarr[v].vex << ", ";
    }
}

void DFS(Graph *G, int v) {
    ArcNode *p;
    dfsvisit[v] = 1;//标记该结点已被访问
    Visit(G, v);//查看结点值
    p = G->vexarr[v].firstarc;
    while (p != nullptr) {
        if (dfsvisit[p->adjvex] == 0) { //边结点未被访问，则递归访问
            DFS(G, p->adjvex);
        }
        p = p->nextarc;//边结点被访问过，则跳过看下一个边结点
    }
}

// 深度优先搜索
void DeepFirstSearch(Graph *G) {
    for (int i = 1; i <= G->n; ++i) {
        if (dfsvisit[i] == 0) { //根结点未被访问时
            DFS(G, i);
        }
    }
}

void BFS(Graph *G, int v) {
    ArcNode *p;
    int queue[MAXSIZE], front = 0, rear = 0;//定义辅助循环队列
    int j;
    Visit(G, v);
    bfsvisit[v] = 1;//标记该结点已被访问
    queue[rear] = v;//将顶点入队
    rear = (rear + 1) % MAXSIZE;
    while (rear != front) { // 队非空就遍历
        j = queue[front];
        front = (front + 1) % MAXSIZE;
        p = G->vexarr[j].firstarc;// p指向队顶第一边
        while (p != nullptr) {
            if (bfsvisit[p->adjvex] == 0) { //当前邻接点未被访问，则进队
                Visit(G, p->adjvex); //访问当前结点
                bfsvisit[p->adjvex] = 1;
                // 访问后再进队
                queue[rear] = p->adjvex;
                rear = (rear + 1) % MAXSIZE;
            }
            p = p->nextarc;//p指向下一条边
        }
    }
}

// 广度优先搜素
void BreadFirstSearch(Graph *G) {
    for (int i = 1; i <= G->n; ++i) {
        if (bfsvisit[i] == 0) {
            BFS(G, i);
        }
    }
}

/*运行过程
*
输入结点个数, 边的条数(如: 5 7): 5 7
输入根节点值: 1
输入根节点连接的边结点值: 2 4 5 -1
输入根节点值: 2
输入根节点连接的边结点值: 5 3 -1
输入根节点值: 3
输入根节点连接的边结点值: 1 -1
输入根节点值: 4
输入根节点连接的边结点值: 3 -1
输入根节点值: 5
输入根节点连接的边结点值: -1

深度优先遍历为: 1, 2, 5, 3, 4,
广度优先遍历为: 1, 2, 4, 5, 3,
 *
 */

int main() {
    Graph *G;
    CreateGraph(G);
    cout << endl <<"深度优先遍历为: ";
    DeepFirstSearch(G);
    cout << endl;
    cout << "广度优先遍历为: ";
    BreadFirstSearch(G);
    return 0;
}