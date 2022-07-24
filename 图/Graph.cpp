//
// Created by yzm-dev on 2022/5/24.
//
#include <iostream>

using namespace std;
// 采用邻接表法实现图
const int MAXSIZE = 30; //顶点最多的个数

// 边结点定义
typedef struct ArcNode {
    int arcdata;
    struct ArcNode *nextarc; //边指向下一条边
}ArcNode;

// 定点结点定义
typedef struct VexNode {
    int vexdata;
    ArcNode *fristarc; //顶点指向第一条边
}VexNode;

// 图的定义
typedef struct {
    int n, e; //顶点，边的个数
    VexNode vexarr[MAXSIZE];
}Graph;


