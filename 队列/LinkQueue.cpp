//
// Created by yzm-dev on 2022/3/29.
//
#include <iostream>

using namespace std;
// 链队列的定义
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

// 头，尾指针的定义
typedef struct LinkQueue {
    struct LinkNode *head;
    struct LinkNode *tail;
} LinkQueue;

// 链队列初始化
void InitQueue(LinkQueue &Q) {
    Q.head = Q.tail = new LinkNode;
    Q.head->next = nullptr;
}

// 链队列判空
bool IsEmpty(LinkQueue Q) {
    if (Q.head == Q.tail) return true;
    else return false;
}

// 入队
void EnQueue(LinkQueue &Q, int x) {
    LinkNode *p = new LinkNode;
    p->data = x;
    p->next = nullptr; // p结点总是插入在链尾结点
    Q.tail->next = p;
    Q.tail = p; // 将tail指针指向最后一个结点
}

// 出队
bool DeQueue(LinkQueue &Q, int &e) {
    if (Q.head == Q.tail) return false; // 队为空
    LinkNode *p = Q.head->next;
    e = p->data;
    Q.head->next = p->next;
    if (Q.tail == p) {  // 删除最后一个结点
        Q.tail = Q.head; // 将tail重新指向head
    }
    delete p;
    return true;
}

// 打印链队元素
bool PrintQueue(LinkQueue Q) {
    if (Q.head == Q.tail) return false; // 队为空
    cout << "先出 <- 后进 : ";
    LinkNode *q = Q.head->next;
    while(q != nullptr) {
        cout << q->data << ", ";
        q = q->next;
    }
    cout << endl;
    return true;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    for (int i = 1; i <= 20; ++i) {
        EnQueue(Q, i);
    }
    PrintQueue(Q);
    for (int i = 0; i < 4; ++i) {
        int x;
        if (DeQueue(Q, x)) {
            cout << "出队: " << x << endl;
        } else {
            cout << "队为空！" << endl;
        }
        PrintQueue(Q);
    }
    return 0;
}