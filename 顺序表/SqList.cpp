//
// Created by yzm-dev on 2022/3/25.
//
#include <iostream>

using namespace std;

// 顺序表的最大长度
const int maxSize = 20;
// 定义顺序表
typedef struct SqList {
    int data[maxSize];
    int length;
} SqList;

// 顺序表的初始化
void SqListInit(SqList &S) {
    for (int i = 0; i < maxSize; ++i) {
        S.data[i] = -1;
    }
    S.length = 0;
}

// 输出顺序表中的元素
void PrintSqList(SqList S) {
    for (int i = 0; i < S.length; ++i) {
        cout << S.data[i] << ", ";
    }
    cout << "length=" << S.length << endl;
}

// 顺序表的插入（按位序插入，位序从1开始）
bool SqListInsert(SqList &S, int i, int v) {
    if (i < 1 || i > S.length + 1) {  // i的合法位置为[1,length+1]
        return false;
    } else if (S.length >= maxSize) {  // 顺序表已经装满
        return false;
    }
    for (int j = S.length; j <= i; ++j) {  // 将第i->length的元素后移一位
        S.data[j] = S.data[j - 1];
    }
    S.data[i - 1] = v; // 插入元素到i个位置
    S.length++;  // 顺序表的长度+1
    return true;
}

// 顺序表的删除(按位序删除,位序从1开始)
bool SqListDelete(SqList &S, int i, int &e) {
    if (i < 1 || i > S.length) {  // i的合法位置为[1,length]
        return false;
    }
    e = S.data[i - 1];  // 存放删除的第i个元素
    for (int j = i; j <= S.length; ++j) {  // 将第i->length的元素前移一位
        S.data[j - 1] = S.data[j];
    }
    S.length--;  // 顺序表的长度-1
    return true;
}

// 按位序查找
int FindValueByIndex(SqList S, int i) {
    if (i < 1 || i > S.length) {  // i值不合法
        return false;
    }
    return S.data[i - 1];
}

// 按值查找位序
int FindIndexByValue(SqList S, int e) {
    for (int i = 0; i < S.length; ++i) {
        if (S.data[i] == e) {  // 查找成功，返回位序
            return i - 1;
        }
    }
    return false;
}

int main() {
    SqList S;
    SqListInit(S);

    for (int i = 1; i <= 20; ++i) {
        SqListInsert(S, i, i);
    }
    int e;
    SqListDelete(S, 20, e);

    PrintSqList(S);
}