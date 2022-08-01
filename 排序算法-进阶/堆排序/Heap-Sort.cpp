//
// Created by yzm-dev on 2022/6/31.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小

// 返回左孩子结点
int Left(int i) {
    return 2 * i;
}

// 返回右孩子结点
int Right(int i) {
    return (2 * i) + 1;
}

// 大根堆结点调整
void MaxHeap(int a[], int i, int heap_size) {
    int l = Left(i); // i左孩子
    int r = Right(i); // i右孩子
    int largest; // 记录最大值
    if (l <= heap_size && a[l] > a[i])// 左孩子更大
        largest = l;
    else
        largest = i;
    if (r <= heap_size && a[r] > a[largest])// 右孩子更大
        largest = r;
    if (largest != i) { // i自身更大
        Swap(a[largest], a[i]); // i与更大值交换
        MaxHeap(a, largest, heap_size);
    }
}

// 小根堆结点调整
void MinHeap(int a[], int i, int heap_size) {
    int l = Left(i); // i左孩子
    int r = Right(i); // i右孩子
    int smallest; // 记录最小值
    if (l <= heap_size && a[l] < a[i])// 左孩子更小
        smallest = l;
    else
        smallest = i;
    if (r <= heap_size && a[r] < a[smallest])// 右孩子更小
        smallest = r;
    if (smallest != i) { // i自身更小
        Swap(a[smallest], a[i]); // i与更小值交换
        MinHeap(a, smallest, heap_size);
    }
}

// 建立大根堆
void BuildMaxHeap(int a[], int heap_size) {
    for (int i = (heap_size / 2); i >= 1; --i) { //从 (Heap-Size / 2) ~ 1 分支结点依次调整堆结点
        MaxHeap(a, i, heap_size);
    }
}

// 建立小根堆
void BuildMinHeap(int a[], int heap_size) {
    for (int i = (heap_size / 2); i >= 1; --i) { //从 (Heap-Size / 2) ~ 1 分支结点依次调整堆结点
        MinHeap(a, i, heap_size);
    }
}

// 堆升序排序
void HeapSortIncrease(int a[], int heap_size) {
    for (int i = heap_size; i >= 2; --i) {
        Swap(a[i], a[1]); // 每次将a[1]的最大值与最后一个元素交换
        heap_size = heap_size - 1; // 堆大小-1，最后一个元素确定位置不参与下调
        MaxHeap(a, 1, heap_size); // 交换后a[1]元素大根堆下调整
    }
}

// 堆降序排序
void HeapSortDecrease(int a[], int heap_size) {
    for (int i = heap_size; i >= 2; --i) {
        Swap(a[i], a[1]); // 每次将a[1]的最大值与最后一个元素交换
        heap_size = heap_size - 1; // 堆大小-1，最后一个元素确定位置不参与下调
        MinHeap(a, 1, heap_size); // 交换后a[1]元素大根堆下调整
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH); // 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "   堆排序前: ";
    DisplayArr(a, LENGTH);
    cout << "\n  构建大根堆: ";
    BuildMaxHeap(a, LENGTH);
    DisplayArr(a, LENGTH);
    cout << "堆排序升序后: ";
    HeapSortIncrease(a, LENGTH);
    DisplayArr(a, LENGTH);
    cout << "\n  构建小根堆: ";
    BuildMinHeap(a, LENGTH);
    DisplayArr(a, LENGTH);
    cout << "堆排序降序后: ";
    HeapSortDecrease(a, LENGTH);
    DisplayArr(a, LENGTH);
    return 0;
}