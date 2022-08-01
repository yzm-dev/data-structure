//
// Created by yzm-dev on 2022/7/1.
//

#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小
int b[LENGTH + 1]; // 归并排序辅助数组

// 升序合并两区间元素
void MergeIncrease(int a[], int l, int m, int r) {
    for (int p = l; p <= r; p++) { // 将合并区间值复制给辅助数组
        b[p] = a[p];
    }
    int i, j, k;
    for (i = l, j = m + 1, k = i; i <= m && j <= r; ++k) { // 在两有序区间 [l~m], [m~r]内依次比较，教小值先放入 a 数组中
        if (b[i] <= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while (i <= m) a[k++] = b[i++]; // 处理两有序区间中未比较完的一个区间剩余部分
    while (j <= r) a[k++] = b[j++];
}

// 降序合并两区间元素
void MergeDecrease(int a[], int l, int m, int r) {
    for (int p = l; p <= r; p++) { // 将合并区间值复制给辅助数组
        b[p] = a[p];
    }
    int i, j, k;
    for (i = l, j = m + 1, k = i; i <= m && j <= r; ++k) { // 在两有序区间 [l~m], [m~r]内依次比较，教小值先放入 a 数组中
        if (b[i] >= b[j])
            a[k] = b[i++];
        else
            a[k] = b[j++];
    }
    while (i <= m) a[k++] = b[i++]; // 处理两有序区间中未比较完的一个区间剩余部分
    while (j <= r) a[k++] = b[j++];
}

// 归并升序排序
void MergeSortIncrease(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSortIncrease(a, l, m); // (和快速排序思想一致)分治策略，每次换分左右两个区间，两个区间排序，结果合并.
        MergeSortIncrease(a, m + 1, r);
        MergeIncrease(a, l, m, r);
    }
}

// 归并将序排序
void MergeSortDecrease(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSortDecrease(a, l, m); // (和快速排序思想一致)分治策略，每次换分左右两个区间，两个区间排序，结果合并.
        MergeSortDecrease(a, m + 1, r);
        MergeDecrease(a, l, m, r);
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH);// 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "   归并排序前: ";
    DisplayArr(a, LENGTH);
    cout << "  归并排序升序: ";
    MergeSortIncrease(a, 1, LENGTH);
    DisplayArr(a, LENGTH);
    cout << "  归并排序降序: ";
    MergeSortDecrease(a, 1, LENGTH);
    DisplayArr(a, LENGTH);
    return 0;
}