//
// Created by yzm-dev on 2022/3/25.
//
#include <iostream>

using namespace std;

// 单链表的定义(带头节点)
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 单链表的初始化
bool InitList(LinkList &L) {
    L = new LNode;
    if (L == nullptr) return false;
    L->next = nullptr;  // 头结点的后继置空
    return true;
}

// 头插法建立单链表
bool HeadInsert(LinkList &L) {
    L = new LNode; // 申请头结点
    L->next = nullptr;
    int e; // 输入插入的数
    cout << "依次输入插入的数(-99表示结束)" << endl;
    cin >> e;
    while (e != -99) {  // 输入-999结束循环
        LNode *p = new LNode;  // 申请插入节点空间
        p->data = e;
        p->next = L->next; // 修改节点指向
        L->next = p;
        cin >> e;
    }
    return true;
}

// 尾插法建立单链表
bool TailInsert(LinkList &L) {
    L = new LNode; // 申请头结点
    LNode *r = L, *p;  // r为尾指针, p为插入节点
    int e; // e为插入的值
    cout << "依次输入插入的数(-99表示结束)" << endl;
    cin >> e;
    while (e != -99) {
        p = new LNode;
        p->data = e;
        r->next = p;
        r = p;
        cin >> e;
    }
    r->next = nullptr; // 将尾指针后继置空
    return true;
}

// 按位序插入值到单链表(位序从1开始)
bool InsertByIndex(LinkList &L, int i, int e) {
    if (i < 1) return false;
    LNode *p;  // 指针p为工作指针
    int j = 0;  // 用j定位到第i-1个结点（i结点前驱)
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

// 按位序删除单链表中的值(位序从1开始)
bool DeleteByIndex(LinkList &L, int i, int &e) {
    if (i < 1) return false;
    LNode *p;  // 指针p为工作指针
    int j = 0;  // 用j定位到第i-1个结点（i结点前驱)
    p = L;
    while (p != nullptr && j < i - 1) {  // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;  // p为尾部空指针,i值不合法
    if (p->next == nullptr) return false;  // i-1个结点后再无结点
    LNode *q = p->next;
    e = q->data;  // 保存删除的值
    p->next = q->next;
    delete q;  // 释放第i个结点
    return true;
}

// 按位查找，返回第i个元素
LNode *FindByIndex(LinkList L, int i) {
    if (i < 0) {
        return nullptr;
    }
    LNode *p;  // 指针p为工作指针
    int j = 0;  // j表示当前结点
    p = L;
    while (p != nullptr && j < i) {  // 循环找到第i个结点
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *FindByValue(LinkList L, int e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {  // 从第1个节点开始查找值为e的结点
        p = p->next;
    }
    return p;  // 找到后返回该结点的指针
}

// 循环输出单链表的元素
void PrintList(LinkList L) {
    while (L->next != nullptr) {
        cout << L->next->data << ", ";
        L = L->next;
    }
    cout << '\n';
}

int main() {
    LinkList L;
    //InitList(L);
    //HeadInsert(L);
    TailInsert(L);
    //PrintList(L);
    //InsertByIndex(L, 3, 3);
    //int e;
    //DeleteByIndex(L, 2, e);
    //PrintList(L);
    return 0;
}