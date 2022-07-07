//
// Created by yzm-dev on 2022/3/25.
//
#include <iostream>

using namespace std;

// 单链表的定义(不带头节点)
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 单链表的初始化
void InitList(LinkList &L) {
    L = nullptr;  // 头结点的后继置空
}

// 按位序插入
bool InsertByIndex(LinkList &L, int i, int e) {
    if (i < 1) return false;
    if (i == 1){  // 插入第1个结点特殊处理
        LNode *s = new LNode;
        s->data = e;
        s->next = L;
        L = s;  // 头指针指向新结点
        return true;
    }
    LNode *p;  // 指针p为工作指针
    int j = 1;  // 用j定位到第i-1个结点（i结点前驱)
    p = L;
    while (p != nullptr && j < i - 1) {  // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;  // p为尾部空指针,i值不合法
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;  // 将结点s连接到p之后
    return true;
}

/**
 * 其他方法和头结点类型，不再赘述
 */

int main() {
    LinkList L;
    InitList(L);
    InsertByIndex(L, 1, 3);
    return 0;
}