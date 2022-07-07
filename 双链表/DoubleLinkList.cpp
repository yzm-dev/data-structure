//
// Created by yzm-dev on 2022/3/25.
//
#include <iostream>

using namespace std;

// 双链表的定义
typedef struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

// 双链表的初始化
bool InitDLinkList(DLinkList &L) {
    L = new DNode;
    if (L == nullptr) return false;  // 分配内存失败
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

// 在p结点之后插入结点
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == nullptr || s == NULL) {  // 非法参数
        return false;
    }
    s->next = p->next;
    if (p->next != nullptr) {  // 如果p结点有后继结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p结点的后继结点
bool DeleteNextDNode(DNode *p) {
    if (p == nullptr) return false;
    DNode *q = p->next;// 找到p的后继结点q
    if (q == nullptr) return false; // p没有后继
    p->next = q->next;
    if (q->next != nullptr) { // q结点不是最后一个结点
        q->next->prior = p;
    }
    delete q;
    return true;
}

// 双链表的遍历
void DListTraverse(DLinkList L) {
    while (L->next != nullptr) {
        // 一系列用于遍历的操作
    }
}

int main() {
    DLinkList L;
    InitDLinkList(L);

    return 0;
}