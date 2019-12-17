/************************************************************
    File Name : EP30.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 19:47:17
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define MAX_N 354294

int is_val(int n) {
    int x = n, tmp = 0;
    while (x) {
        tmp += pow(x % 10, 5);
        x /= 10;
    }
    return tmp == n;
}

int main() {
    int sum = 0;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}