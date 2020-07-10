/************************************************************
    File Name : quick_sort_v3.cc
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/10 10:52:35
************************************************************/

#include "quick_sort.h"

// 区间左闭右闭
// 无监督partition
void quick_sort_v3(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l], temp;
        do {
            while (arr[x] < z) x++;
            while (arr[y] > z) y--;
            if (x <= y) {
                temp = arr[x], arr[x] = arr[y], arr[y] = temp;
                x++, y--;
            }
        } while (x <= y);
        quick_sort_v3(arr, l, y);
        l = x;
    }
    return;
}