//
// Created by yzm-dev on 2022/3/29.
//
#include <iostream>

using namespace std;
const int MAXSIZE = 20;

// 顺序栈的初始化
typedef struct SqStack {
    int data[MAXSIZE];
    int top;
} SqStack;

// 顺序栈初始化
bool InitStack(SqStack &S) {
    for (int i = 0; i < MAXSIZE; ++i) {
        S.data[i] = 0;
    }
    S.top = -1;
    return true;
}

// 顺序栈的入栈
bool Push(SqStack &S, int e) {
    if (S.top == MAXSIZE - 1){  // 栈满不能再入
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

// 顺序栈的出栈
bool Pop(SqStack &S, int &e) {
    if (S.top == -1) {  // 栈为空不能再出
        return false;
    }
    e = S.data[S.top--];
    return true;
}

// 栈判空
bool EmptyStack(SqStack S) {
    if (S.top == -1) { // 栈为空
        return true;
    } else {
        return false;
    }
}

// 查看栈顶元素
bool GetTop(SqStack S, int &e) {
    if (S.top == -1) { // 栈为空
        return false;
    } else {
        e = S.data[S.top];
        return true;
    }
}

// 打印栈元素(从栈底往栈顶打印)
bool PrintStack(SqStack S) {
    if (S.top == -1) return false;  // 栈为空
    cout << "栈底 -> 栈顶 : ";
    for (int i = 0; i <= S.top ; i++) {
        cout << S.data[i] << ", ";
    }
    cout << endl;
    return true;
}

int main() {
    SqStack S;
    InitStack(S);
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