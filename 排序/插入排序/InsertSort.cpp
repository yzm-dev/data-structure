//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

// 升序排序 (插入排序)
int AscendSort(int a[], int length) {
    int i, j;
    int TempMin; // 辅助变量
    for (i = 1; i < length; ++i) { // 从 1 ~ length-1 每个位置往前遍历插入位置
        if (a[i] < a[i - 1]) {
            TempMin = a[i]; // 先把a[i]作为临时最小
            for (j = i - 1; TempMin < a[j] && j >=0; j--) { // 比较从 i-1 到开始的有位置，找插入点
                a[j + 1] = a[j]; // 不符合的往后移位
            }
            a[j + 1] = TempMin; // 插入到所在位置
        }
    }
}

// 降序排序 (插入排序)
int DescendSort(int a[], int length) {
    int i, j;
    int TempMax; // 辅助变量
    for (i = 1; i < length; ++i) { // 从 1 ~ length-1 每个位置往前遍历插入位置
        if (a[i] > a[i - 1]) {
            TempMax = a[i]; // 先把a[i]作为临时最大
            for (j = i - 1; TempMax > a[j] && j >=0; j--) { // 比较从 i-1 到开始的有位置，找插入点
                a[j + 1] = a[j]; // 不符合的往后移位
            }
            a[j + 1] = TempMax; // 插入到所在位置
        }
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(插入排序)前：";
    ArrShow(a, length);

    AscendSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendSort(a, length);
    cout << "降序排序后：";
    ArrShow(a, length);
}