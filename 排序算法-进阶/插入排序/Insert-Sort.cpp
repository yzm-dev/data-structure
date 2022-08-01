//
// Created by yzm-dev on 2022/6/31.
//
#include <iostream>
#include "../../Tools/GenerateRandom.h"

using namespace std;

const int LENGTH = 20; // 设置数组的大小

// 插入升序排序
void InsertSortIncrease(int a[]) {
    for (int i = 2; i <= LENGTH; ++i) {
        int key = a[i];// 暂存i的值
        int j = i - 1; // j为辅助指针，依次往左扫描
        while (j > 0 && key < a[j]) { // 满足条件的往右移位
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// 插入降序排序
void InsertSortDecrease(int a[]) {
    for (int i = 2; i <= LENGTH; ++i) {
        int key = a[i];// 暂存i的值
        int j = i - 1; // j为辅助指针，依次往左扫描
        while (j > 0 && key > a[j]) { // 满足条件的往右移位
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[LENGTH + 1];
    GenerateRandomIntArr(a, 1, 100, LENGTH);// 生成 1 ~ 100 内整数,填充数组 a[1~LENGTH]
    cout << "   插入排序前: ";
    DisplayArr(a, LENGTH);
    cout << "升序插入排序后: ";
    InsertSortIncrease(a);
    DisplayArr(a, LENGTH);
    cout << "降序插入排序后: ";
    InsertSortDecrease(a);
    DisplayArr(a, LENGTH);
    return 0;
}