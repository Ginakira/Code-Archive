/************************************************************
    File Name : EP34.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 20:05:23
************************************************************/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define MAX_N 2903040

int factorial(int x) {
    if (x == 0) return 1;
    if (x == 1) return 1;
    return x * factorial(x - 1);
}

int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += factorial(x % 10);
        x /= 10;
    }
    return tmp == n;
}

int main() {
    int sum = 0;
    for (int i = 3; i <= MAX_N; ++i) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}