//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;


// 升序排序（选择排序）
int AscendSort(int a[], int length) {
    for (int i = 0; i < length - 1; ++i) {  // 循环 length-1 趟
        int MinIndex = i; // 最小值索引
        for (int j = i + 1; j < length; ++j) { // 每趟从 i+1 开始依次遍历到数组末尾找最小值索引
            if (a[MinIndex] > a[j]) {
                MinIndex = j;  // 更新此趟最小值索引
            }
        }
        if (MinIndex != i) { // 最小值不为i，交换值
            Swap(a[i], a[MinIndex]);
        }
    }
}

// 降序排序（选择排序）
int DescendSort(int a[], int length) {
    for (int i = 0; i < length - 1; ++i) {  // 循环 length-1 趟
        int MaxIndex = i; // 最大值索引
        for (int j = i + 1; j < length; ++j) { // 每趟从 i+1 开始依次遍历到数组末尾找最大值索引
            if (a[MaxIndex] < a[j]) {
                MaxIndex = j;  // 更新此趟最小值索引
            }
        }
        if (MaxIndex != i) { // 最大值不为i，交换值
            Swap(a[i], a[MaxIndex]);
        }
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(选择排序)前：";
    ArrShow(a, length);

    AscendSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendSort(a, length);
    cout << "降序排序后：";
    ArrShow(a, length);
}