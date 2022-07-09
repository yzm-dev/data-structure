//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"
using namespace std;

// 一趟划升序分
int AscendPartition(int a[], int low, int high) {
    int pivot = a[low]; // 第一个元素作为基准
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            --high; // high指向的元素大于等于基准往左移
        }
        a[low] = a[high]; // 不满足将会high指向的值复给low指向的值
        while (low < high && a[low] <= pivot) {
            ++low; // low指向的元素小于等于基准往右移
        }
        a[high] = a[low]; // 不满足将会low指向的值复给high指向的值
    }
    a[low] = pivot; // low与high相等，确定最终位置
    return low; // 返回基准的下标
}

// 一趟划降序序分
int DescendPartition(int a[], int low, int high) {
    int pivot = a[low]; // 第一个元素作为基准
    while (low < high) {
        while (low < high && a[high] <= pivot)  --high; // high指向的元素小于等于基准往左移
        a[low] = a[high]; // 不满足将会high指向的值复给low指向的值
        while (low < high && a[low] >= pivot) ++low; // low指向的元素大于等于基准往右移
        a[high] = a[low]; // 不满足将会low指向的值复给high指向的值
    }
    a[low] = pivot; // low与high相等，确定最终位置
    return low; // 返回基准的下标
}

// 升序排序
int AscendQuickSort(int a[], int low, int high) {
    if (low < high) {  // 递归跳出条件
        int pivotpos = AscendPartition(a, low, high); // 划分左右两个字表，获取基准下标
        AscendQuickSort(a, low, pivotpos - 1); // 递归处理左字表
        AscendQuickSort(a, pivotpos + 1, high);// 递归处理右字表
    }
}

// 降序排序
int DescendQuickSort(int a[], int low, int high) {
    if (low < high) {  // 递归跳出条件
        int pivotpos = DescendPartition(a, low, high); // 划分左右两个字表，获取基准下标
        DescendQuickSort(a, low, pivotpos - 1); // 递归处理左字表
        DescendQuickSort(a, pivotpos + 1, high);// 递归处理右字表
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(快速排序)前：";
    ArrShow(a, length);

    AscendQuickSort(a, 0, length - 1);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendQuickSort(a, 0, length - 1);
    cout << "降序排序后：";
    ArrShow(a, length);
}