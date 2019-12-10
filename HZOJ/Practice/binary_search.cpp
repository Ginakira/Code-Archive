/************************************************************
    File Name : divide.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/10 18:18:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int f(int x) { return x * x; }

int my_binary_search(int *arr, int x, int n) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int ex_binary_search(int (*arr)(int), int x, int n) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr(mid) == x) return mid;
        if (arr(mid) < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int recursive_binary_search(int *arr, int head, int tail, int x) {
    if (head > tail) return -1;
    int mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) {
        head = mid + 1;
    } else {
        tail = mid - 1;
    }
    return recursive_binary_search(arr, head, tail, x);
}

// 00000011111 找第一个1
int binary_search1(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] > x)
            tail = mid;
        else
            head = mid + 1;
    }
    return head == n ? -1 : head;
}

// 1111110000 找最后一个1
int binary_search0(int *arr, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == 1)
            head = mid;
        else
            tail = mid - 1;
    }
    return head;
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << binary_search0(arr, n);
    return 0;
}