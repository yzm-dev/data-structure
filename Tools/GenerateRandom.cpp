//
// Created by yzm-dev on 2022/7/7.
//

#include "GenerateRandom.h"

// 生成 [start, end] 的随机数
void GetRandomIntArr(int a[],int start, int end, int length) {
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        a[i] = (rand() % (end - start + 1)) + start;
    }
}

// 生成 [start, end] 的随机数
// 从数组下标 1~length
void GenerateRandomIntArr(int a[],int start, int end, int length) {
    srand(time(nullptr));
    a[0] = 0;
    for (int i = 1; i <= length; ++i) {
        a[i] = (rand() % (end - start + 1)) + start;
    }
}

// 交换两个值
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 显示数组内所有值
void ArrShow(int a[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}

// 显示数组内所有值从下标1开始
void DisplayArr(int a[], int length) {
    for (int i = 1; i <= length; ++i) {
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}


