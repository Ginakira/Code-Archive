/************************************************************
    File Name : quick_sort_v4.cc
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 10:55:47
************************************************************/

#include "quick_sort.h"

#define swap(a, b)            \
    {                         \
        __typeof(a) temp = a; \
        a = b, b = temp;      \
    }

// 区间左闭右闭
// 三点取中法

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

void quick_sort_v4(int *arr, int l, int r) {
    while (r - l >= 16) {
        int x = l, y = r, z = arr[l], temp;
        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                temp = arr[x], arr[x] = arr[y], arr[y] = temp;
                x++, y--;
            }
        } while (x <= y);
        quick_sort_v4(arr, l, y);
        l = x;
    }
    if (l < r) unguarded_insert_sort(arr, l, r);
    return;
}

#undef swap