//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

// 升序排序
int AscendSort(int a[], int length) {
    for (int i = 0; i < length - 1; ++i) {  // 循环冒泡 length-1 趟
        for (int j = 1; j <= length - 1 - i; ++j) { // 每趟确定一个末尾的最大值
            if (a[j - 1] > a[j]) { // 冒泡过程后面比前面小则交换
                Swap(a[j - 1], a[j]);
            }
        }
    }
}

// 降序排序
int DescendSort(int a[], int length) {
    for (int i = 0; i < length - 1; ++i) {  // 循环冒泡 length-1 趟
        for (int j = 1; j <= length - 1 - i; ++j) { // 每趟确定一个末尾的最小值
            if (a[j - 1] < a[j]) { // 冒泡过程后面比前面小则交换
                Swap(a[j - 1], a[j]);
            }
        }
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(冒泡排序)前：";
    ArrShow(a, length);

    AscendSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendSort(a, length);
    cout << "降序排序后：";
    ArrShow(a, length);
}