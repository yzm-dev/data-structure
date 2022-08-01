//
// Created by yzm-dev on 2022/7/7.
//
#ifndef C_PROJECT_GENERATERANDOM_H
#define C_PROJECT_GENERATERANDOM_H

#include <cstdlib>
#include <iostream>
#include <ctime>

// 生成 [start, end] 的随机数
void GetRandomIntArr(int a[],int start, int end, int length);

// 生成 [start, end] 的随机数
// 从数组下标 1~length
void GenerateRandomIntArr(int a[],int start, int end, int length);

// 交换两个值
void Swap(int &a, int &b);

// 显示数组内所有值
void ArrShow(int a[], int length);

// 显示数组内所有值从下标1开始
void DisplayArr(int a[], int length);


#endif //C_PROJECT_GENERATERANDOM_H


