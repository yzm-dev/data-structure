//
// Created by yzm-dev on 2022/6/31.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小

// 划分枢轴
int PartationIncrease(int a[], int l, int r) {
    int pivot = a[r]; // 指定枢轴元素
    int i = l - 1; // i 指向0空位置
    for (int j = l; j <= r - 1; ++j) { // j从 1 ~ r-1 依次遍历
        if (a[j] <= pivot) { // 遇到比枢轴小的则交换, i+1
            ++i;
            Swap(a[i], a[j]);
        }
    }
    Swap(a[i + 1], a[r]); // 此时已经确定枢轴位置为 i+1,与a[r]交换
    return i + 1; // 返回枢轴位置
}

// 划分枢轴
int PartationDecrease(int a[], int l, int r) {
    int pivot = a[r]; // 指定枢轴元素
    int i = l - 1; // i 指向0空位置
    for (int j = l; j <= r - 1; ++j) { // j从 1 ~ r-1 依次遍历
        if (a[j] >= pivot) { // 遇到比枢轴小的则交换, i+1
            ++i;
            Swap(a[i], a[j]);
        }
    }
    Swap(a[i + 1], a[r]); // 此时已经确定枢轴位置为 i+1,与a[r]交换
    return i + 1; // 返回枢轴位置
}

// 快速升序排序
void QuickSortIncrease(int a[], int l, int r) {
    if (l < r) {
        int p = PartationIncrease(a, l, r); // 确定换分枢轴位置
        //分治思想，递归划分成多个子区间，排序后合并(此算法不需要合并)
        QuickSortIncrease(a, l, p - 1);
        QuickSortIncrease(a, p + 1, r);
    }
}

// 快速降序排序
void QuickSortDecrease(int a[], int l, int r) {
    if (l < r) {
        int p = PartationDecrease(a, l, r); // 确定换分枢轴位置
        //分治思想，递归划分成多个子区间，排序后合并(此算法不需要合并)
        QuickSortDecrease(a, l, p - 1);
        QuickSortDecrease(a, p + 1, r);
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH);// 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "   快速排序前: ";
    DisplayArr(a, LENGTH);
    cout << "升序快速排序后: ";
    QuickSortIncrease(a, 1, LENGTH);
    DisplayArr(a, LENGTH);
    cout << "降序快速排序后: ";
    QuickSortDecrease(a, 1, LENGTH);
    DisplayArr(a, LENGTH);
    return 0;
}