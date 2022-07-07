//
// Created by yzm-dev on 2022/3/29.
//
#include <iostream>

using namespace std;
const int MAXSIZE = 20;

// 顺序队列的定义(循环队列)
typedef struct SqQueue {
    int data[MAXSIZE];
    int front, rear;
} SqQueue;

// 循环队列的初始化
bool InitQueue(SqQueue &Q) {
    for (int i = 0; i < MAXSIZE; ++i) {
        Q.data[i] = 0;
    }
    Q.front = 0;
    Q.rear = 0;
    return true;
}

// 循环队列的入队
bool EnQueue(SqQueue &Q, int e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) return false; // 队满
    Q.data[Q.rear] = e; // 入队, rear+1
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

// 循环队列的出队
bool DeQueue(SqQueue &Q, int &e) {
    if (Q.rear == Q.front) return false; // 队空
    e = Q.data[Q.front]; // 存取出队元素, front+1
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

// 循环队列判空
bool EmptyQueue(SqQueue Q) {
    if (Q.rear == Q.front) return true; // 队空
    else return false;
}

// 打印循环队列的元素
bool PrintQueue(SqQueue Q) {
    if (Q.rear == Q.front) return false; // 队空
    cout << "先出 -> 后进 : ";
    for (int i = Q.front; i % MAXSIZE != Q.rear; i++) {
        cout << Q.data[i] << ", ";
    }
    cout << endl;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    for (int i = 1; i <= 20; ++i) {
        EnQueue(Q, i);
    }
    PrintQueue(Q);
    int x;
    DeQueue(Q, x);
    cout << x << endl;
    PrintQueue(Q);
    return 0;
}