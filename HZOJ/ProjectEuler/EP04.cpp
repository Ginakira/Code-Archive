/************************************************************
    File Name : EP04.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 18:08:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int is_val(int n, int base) {
    int x = n, tmp = 0;
    while (x) {
        tmp = tmp * base + x % base;
        x /= base;
    }
    return tmp == n;
}

int main() {
    int ans = 0;
    for (int i = 100; i <= 999; ++i) {
        for (int j = i; j <= 999; ++j) {
            if (is_val(i * j, 10) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}