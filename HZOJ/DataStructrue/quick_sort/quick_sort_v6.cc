/************************************************************
    File Name : quick_sort_v6.cc
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 11:20:04
************************************************************/

#include "quick_sort.h"

#define swap(a, b)            \
    {                         \
        __typeof(a) temp = a; \
        a = b, b = temp;      \
    }

// 区间左闭右闭
// 基准值：三点取中法

static void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    swap(arr[l], arr[ind]);
    for (int i = l + 2; i <= r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
    return;
}

static inline int median_number(int *arr, int l, int r) {
    int a = arr[l], b = arr[r], c = arr[(l + r) >> 1];
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return b;
}

void quick_sort_v6(int *arr, int l, int r) {
    while (r - l >= 16) {
        int x = l, y = r, z = median_number(arr, l, r);
        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sort_v6(arr, l, y);
        l = x;
    }
    if (l < r) unguarded_insert_sort(arr, l, r);
    return;
}

#undef swap