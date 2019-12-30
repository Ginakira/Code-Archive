/************************************************************
    File Name : EP42.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 15:34:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include "input_42"
using namespace std;

int triangle(int n) { return n * (n + 1) / 2; }

bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x)
        l = mid + 1;
    else
        r = mid - 1;
    return binary_search(func, l, r, x);
}

int is_val(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; ++i) {
        sum += str[i] - 'A' + 1;
    }
    return binary_search(triangle, 1, sum, sum);
}

int main() {
    int n = sizeof(str) / 100, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (is_val(str[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}