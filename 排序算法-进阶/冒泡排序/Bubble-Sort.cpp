//
// Created by yzm-dev on 2022/7/1.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小
// 冒泡升序排序
void BubbleSortIncrease(int a[]) {
    for (int i = LENGTH; i >= 2; --i) { // 从 length ~ 2， 每次冒泡数组确定一个 i 的位置
        for (int j = 1; j < i; ++j) { // 从 1 ~ i, 依次两两比较
            if (a[j] > a[j + 1]) { // 左边比右边大则交换
                Swap(a[j], a[j + 1]);
            }
        }
    }
}

// 冒泡降序排序
void BubbleSortDecrease(int a[]) {
    for (int i = LENGTH; i >= 2; --i) { // 从 length ~ 2， 每次冒泡数组确定一个 i 的位置
        for (int j = 1; j < i; ++j) { // 从 1 ~ i, 依次两两比较
            if (a[j] < a[j + 1]) { // 左边比右边小则交换
                Swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH);// 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "    冒泡排序前: ";
    DisplayArr(a, LENGTH);
    cout << "冒泡升序排序后: ";
    BubbleSortIncrease(a);
    DisplayArr(a, LENGTH);
    cout << "冒泡降序排序后: ";
    BubbleSortDecrease(a);
    DisplayArr(a, LENGTH);
    return 0;
}