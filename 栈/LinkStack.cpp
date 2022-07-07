//
// Created by yzm-dev on 2022/3/29.
//
#include <iostream>

using namespace std;

// 链栈的定义
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} *LinkStack;

// 链栈的初始化(带头结点)
bool InitLinkStack(LinkStack &S) {
    S = new LinkNode;
    S->next = nullptr;
    return true;
}

// 链栈的入栈
bool Push(LinkStack &S, int e) {
    LinkNode *p = new LinkNode;
    p->data = e;
    p->next = S->next;
    S->next = p;
    return true;
}

// 链栈的出栈
bool Pop(LinkStack &S, int &e) {
    if (S->next == nullptr) return false; // 链栈为空
    LinkNode *q = S->next;
    e = q->data;
    S->next = q->next;
    delete q;
    return true;
}

// 链栈的打印(栈顶 -> 栈底)
bool PrintStack(LinkStack S) {
    if (S->next == nullptr) return false; // 链栈为空
    LinkNode *p = S->next;
    cout << "栈顶 -> 栈底 : ";
    while (p != nullptr) {
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
    return true;
}

// 查看栈顶元素
bool GetTop(LinkStack S, int &e) {
    if (S->next == nullptr) return false; // 链栈为空
    e = S->next->data;
    return true;
}

//栈是否为空
bool EmptyStack(LinkStack S) {
    if (S->next == nullptr) return true; // 栈为空
    return false;
}

int main() {
    LinkStack S;
    InitLinkStack(S);
    for (int i = 1; i <= 10; ++i) {
        Push(S, i);
    }
    PrintStack(S);
    int x;
    Pop(S, x);
    cout << x << endl;
    PrintStack(S);
    return 0;
}