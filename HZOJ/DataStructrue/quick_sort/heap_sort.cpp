/************************************************************
    File Name : heap_sort.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 11:37:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000000

#define swap(a, b)              \
    {                           \
        __typeof(a) __temp = a; \
        a = b, b = __temp;      \
    }

#define TEST(func, arr, l, r)                                             \
    {                                                                     \
        int *temp = (int *)malloc(sizeof(int) * (r - l + 1));             \
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
        free(temp);                                                       \
    }

int *gen_data(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n;
    }
    return arr;
}

int check(int *arr, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

void up_maintain(int *arr, int ind) {
    while (ind > 1 && arr[ind] > arr[ind >> 1]) {
        swap(arr[ind], arr[ind >> 1]);
        ind >>= 1;
    }
    return;
}

void down_maintain(int *arr, int ind, int n) {
    int temp;
    while (ind << 1 <= n) {
        temp = ind;
        if (arr[ind << 1] > arr[temp]) temp = ind << 1;
        if ((ind << 1 | 1) <= n && arr[ind << 1 | 1] > arr[temp])
            temp = ind << 1 | 1;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
}

void heap_sort(int *arr, int l, int r) {
    int *brr = arr + l - 1, n = r - l + 1;
    for (int i = 2; i <= n; ++i) {
        up_maintain(brr, i);
    }
    for (int i = n; i > 1; --i) {
        swap(brr[1], brr[i]);
        down_maintain(brr, 1, i - 1);
    }
    return;
}

int main() {
    srand(time(0));
    int *arr = gen_data(MAX_N);
    TEST(heap_sort, arr, 0, MAX_N - 1);
    return 0;
}