//
// Created by yzm-dev on 2022/7/7.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

// 升序排序
int AscendSort(int a[], int length) {
    int i, j, k, d;
    // d为步长，每次减为原来的一半。
    for (d = length / 2; d > 0; d /= 2) {
        // 共d个组，对每一组都执行直接插入排序
        for (i = 0; i < d; i++) {
            for (j = i + d; j < length; j += d) {
                // 如果a[j] < a[j-d]，则寻找a[j]位置，并将后面数据的位置都后移。
                if (a[j] < a[j - d]) {
                    int temp = a[j];
                    for (k = j - d; k >= 0 && a[k] > temp; k -= d) {
                        a[k + d] = a[k];
                    }
                    a[k + d] = temp;
                }
            }
        }
    }
}

// 降序排序
int DescendSort(int a[], int length) {
    int i, j, k, d;
    // d为步长，每次减为原来的一半。
    for (d = length / 2; d > 0; d /= 2) {
        // 共d个组，对每一组都执行直接插入排序
        for (i = 0; i < d; i++) {
            for (j = i + d; j < length; j += d) {
                // 如果a[j] > a[j-d]，则寻找a[j]位置，并将后面数据的位置都后移。
                if (a[j] > a[j - d]) {
                    int temp = a[j];
                    for (k = j - d; k >= 0 && a[k] < temp; k -= d) {
                        a[k + d] = a[k];
                    }
                    a[k + d] = temp;
                }
            }
        }
    }
}

int main() {
    int a[20];
    int length = 20;
    GetRandomIntArr(a, 1, 100, length);  // 生成 1 ~ 100 内整数

    cout << "(希尔排序)前：";
    ArrShow(a, length);

    AscendSort(a, length);
    cout << "升序排序后：";
    ArrShow(a, length);

    DescendSort(a, length);
    cout << "降序排序后：";
    ArrShow(a, length);
}

