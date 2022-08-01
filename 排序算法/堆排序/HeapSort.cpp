//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

// 大根堆结点下坠函数
void HeadMaxAdjust(int a[], int k, int length) {
    int temp = a[k - 1]; // 暂存结点的值
    for (int i = 2 * k; i <= length; i *= 2) { // 循环遍历左孩子
        if (i < length && (a[i - 1] < a[i])) {
            i++; // 右孩子的值更大，指向右孩子
        }
        if (temp >= a[i - 1]){
            break; // 不需要下坠
        }
        else {
            a[k - 1] = a[i - 1];  // 将k的右孩子的值赋给k
            k = i;
        }
    }
    a[k - 1] = temp; // 结点最终下坠的位置
}

// 小根堆结点下坠函数
void HeadMinAdjust(int a[], int k, int length) {
    int temp = a[k - 1]; // 暂存结点的值
    for (int i = 2 * k; i <= length; i *= 2) { // 循环遍历左孩子
        if (i < length && (a[i - 1] > a[i])) {
            i++; // 右孩子的值更小，指向右孩子
        }
        if (temp <= a[i - 1]){
            break; // 不需要下坠
        }
        else {
            a[k - 1] = a[i - 1];  // 将k的右孩子的值赋给k
            k = i;
        }
    }
    a[k - 1] = temp; // 结点最终下坠的位置
}

// 构建大根堆
void BuildMaxHeap(int a[], int lenght) {
    for (int i = (lenght / 2); i > 0; i--) { // 从分支结点 length/2 ~ 1 依次遍历下坠
        HeadMaxAdjust(a, i, lenght);
    }
}

// 构建小根堆
void BuildMinHeap(int a[], int lenght) {
    for (int i = (lenght / 2); i > 0; i--) { // 从分支结点 length/2 ~ 1 依次遍历下坠
        HeadMinAdjust(a, i, lenght);
    }
}

// 升序排序
int AscendHeapSort(int a[], int length) {
    // 构建大根堆
    BuildMaxHeap(a, length);
    for (int i = length; i > 1; --i) {  // length - 1 趟交换和建堆
        Swap(a[0], a[i - 1]); // 堆顶与顶底元素交换
        HeadMaxAdjust(a, 1, i - 1);
    }
}

// 降序序排序
int DescendHeapSort(int a[], int length) {
    // 构建小根堆
    BuildMinHeap(a, length);
    for (int i = length; i > 1; --i) {  // length - 1 趟交换和建堆
        Swap(a[0], a[i - 1]); // 堆顶与顶底元素交换
        HeadMinAdjust(a, 1, i - 1);
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(堆排序)前：";
    ArrShow(a, length);

    AscendHeapSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendHeapSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

}