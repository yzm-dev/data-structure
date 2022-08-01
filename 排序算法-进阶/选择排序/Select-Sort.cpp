//
// Created by yzm-dev on 2022/7/1.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小

// 选择排序升序
void SelectSortIncrease(int a[]) {
    int MinIndex; // 最小值辅助下标
    for (int i = 1; i <= LENGTH; ++i) { // 从 1~length,依次遍历数组，每次找到确定存放在 i 位置的元素
        MinIndex = i;
        for (int j = i + 1; j <= LENGTH; ++j) { // 从 i+1~length遍历比较，找到最小值得下标
            if (a[MinIndex] > a[j]) MinIndex = j;
        }
        if (a[MinIndex] != a[i]) Swap(a[i], a[MinIndex]); // 交换 i 与后方最小的元素值, 确定 i 元素的最终位置
    }
}

// 选择降序升序
void SelectSortDecrease(int a[]) {
    int MaxIndex; // 最大值辅助下标
    for (int i = 1; i <= LENGTH; ++i) { // 从 1~length,依次遍历数组，每次找到确定存放在 i 位置的元素
        MaxIndex = i;
        for (int j = i + 1; j <= LENGTH; ++j) { // 从 i+1~length遍历比较，找到最大值得下标
            if (a[MaxIndex] < a[j]) MaxIndex = j;
        }
        if (a[MaxIndex] != a[i]) Swap(a[i], a[MaxIndex]); // 交换 i 与后方最大的元素值, 确定 i 元素的最终位置
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH);// 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "    选择排序前: ";
    DisplayArr(a, LENGTH);
    cout << "选择升序排序后: ";
    SelectSortIncrease(a);
    DisplayArr(a, LENGTH);
    cout << "选择降序排序后: ";
    SelectSortDecrease(a);
    DisplayArr(a, LENGTH);
    return 0;
}