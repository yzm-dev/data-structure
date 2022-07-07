//
// Created by yzm-dev on 2022/3/28.
//
#include <iostream>

using namespace std;

// 定义循环单链表
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化循环单链表
bool InitList(LinkList &L) {
    L = new LNode; // 申请头结点空间
    if (L == nullptr) return false; // 内存分配失败
    L->next = L; // 头结点next指向头结点
    return true;
}

// 循环单链表的插入(头插法）
bool InsertList(LinkList &L, int e) {
    LNode *p = new LNode;
    p->data = e;
    if (L->next == L) {  // 链表中没有结点时
        L->next = p;
        p->next = L;
    } else {  // 链表中存在结点时
        p->next = L->next;
        L->next = p;
    }
    return true;
}

// 删除指定数值的结点
bool DeleteListValue(LinkList &L, int x, int &e) {
    if (L->next == L) return false;  // 循环链表为空
    LNode *p = L;  // p结点为工作结点，找到需要删除结点的前一个结点
    while (p->next->data != x) {
        if (p->next == L) {  // 找不到改元素
            e = -1;
            cout << "删除的值不存在!" << endl;
            return false;
        }
        p = p->next;
    }
    e = p->next->data;
    p->next = p->next->next;  // 删除p结点之后要删除的结点
}

// 打印循环链表(从头结点依次打印)
bool PrintList(LinkList L) {
    if (L->next == L) return false; // 循环链表为空
    LNode *p = L->next;
    while(p != L) {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList L) {
    if (L->next == L) {
        return true;
    } else {
        return false;
    }
}

int main() {
    LinkList L;
    InitList(L);
    for (int i = 1; i <= 13; ++i) {
        InsertList(L, i);
    }
    PrintList(L);
    int x;
    DeleteListValue(L, 20, x);
    cout << x << endl;
    PrintList(L);
    return 0;
}