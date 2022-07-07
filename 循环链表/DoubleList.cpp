//
// Created by yzm-dev on 2022/3/29.
//
#include <iostream>

using namespace std;

// 循环双链表的定义
typedef struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

// 循环双链表的初始化
bool InitDLinkList(DLinkList &L) {
    L = new DNode;
    if (L == nullptr) return false; // 内存分配失败
    L->prior = L;  // 头结点的 prior 指向头结点
    L->next = L;  // 头结点的 next 指向头结点
    return true;
}

// 插入和删除方法与循环单链表类似，不再赘述

// 判断循环双链表是否为空
bool Empty(DLinkList L) {
    if (L->next == nullptr) return true;
    else return false;
}

int main() {
    return 0;
}
