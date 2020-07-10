/************************************************************
    File Name : quick_sort_v2.cc
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 09:49:15
************************************************************/

#include "quick_sort.h"

// 区间左闭右闭
// 单边递归法 节省一半的递归函数调用
void quick_sort_v2(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        while (x < y) {
            while (x < y && arr[y] >= z) --y;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort_v2(arr, l, x - 1);
        l = x + 1;
    }
    return;
}