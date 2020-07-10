/************************************************************
    File Name : quick_sort_test.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 09:22:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#include "quick_sort.h"
using namespace std;
#define MAX_N 10000000

#define TEST(func, arr, l, r)                                             \
    {                                                                     \
        int *temp = (int *)malloc(sizeof(int) * MAX_N);                   \
        memcpy(temp, arr, sizeof(int) * (r - l + 1));                     \
        int b = clock();                                                  \
        func(temp, l, r);                                                 \
        int e = clock();                                                  \
        double t = 1.0 * (e - b) / CLOCKS_PER_SEC;                        \
        if (!check(temp, l, r)) {                                         \
            printf("%s(%.3lf s) is \033[1;35mFAILED\033[0m\n", #func, t); \
        } else {                                                          \
            printf("%s(%.3lf s) is \033[1;32mOK\033[0m\n", #func, t);     \
        }                                                                 \
    }

int *gen_data(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % MAX_N;
    }
    return arr;
}

int check(int *arr, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int main() {
    srand(time(0));
    int *arr = gen_data(MAX_N);
    TEST(quick_sort_v1, arr, 0, MAX_N - 1);
    TEST(quick_sort_v2, arr, 0, MAX_N - 1);
    TEST(quick_sort_v3, arr, 0, MAX_N - 1);
    TEST(quick_sort_v4, arr, 0, MAX_N - 1);
    return 0;
}
