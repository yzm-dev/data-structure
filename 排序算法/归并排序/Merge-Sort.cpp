//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

// 升序合并两个数组
void AscendMerge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[high + 1]; // 辅助数组
    for (int t = low; t <= high; ++t) {  // 将 low~hign 的值复制到数值b相同位置
        b[t] = a[t];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {  // i，j分别扫描两个数组比较大小
        if (b[i] <= b[j]) {
            a[k] = b[i++];  // 将结果放入a数组中
        } else {
            a[k] = b[j++];
        }
    }
    while(i <= mid)  a[k++] = b[i++];  // 一个数组没扫完，复制
    while(j <= high)  a[k++] = b[j++];// 另一个数组没扫完，复制
}

// 降序合并两个数组
void DescendMerge(int a[], int low, int mid, int high) {
    int i, j, k;
    int b[high + 1]; // 辅助数组
    for (int t = low; t <= high; ++t) {  // 将 low~hign 的值复制到数值b相同位置
        b[t] = a[t];
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {  // i，j分别扫描两个数组比较大小
        if (b[i] > b[j]) {
            a[k] = b[i++];  // 将结果放入a数组中
        } else {
            a[k] = b[j++];
        }
    }
    while(i <= mid)  a[k++] = b[i++];  // 一个数组没扫完，复制
    while(j <= high)  a[k++] = b[j++];// 另一个数组没扫完，复制
}

// 升序排序
int AscendMergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // 从中间划分两个子序列
        AscendMergeSort(a, low, mid); // 对左子序列进行递归排序
        AscendMergeSort(a, mid + 1, high); // 对左子序列进行递归排序
        AscendMerge(a, low, mid, high); // 归并
    }
}

// 降序排序
int DescendMergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2; // 从中间划分两个子序列
        DescendMergeSort(a, low, mid); // 对左子序列进行递归排序
        DescendMergeSort(a, mid + 1, high); // 对左子序列进行递归排序
        DescendMerge(a, low, mid, high); // 归并
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(归并排序)前：";
    ArrShow(a, length);


    AscendMergeSort(a, 0, length - 1);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendMergeSort(a, 0, length - 1);
    cout << "降序排序后：";
    ArrShow(a, length);
}