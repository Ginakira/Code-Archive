/************************************************************
    File Name : EP02.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 15:18:58
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 44
#define N 4000000

int fib[MAX_N + 5];

int main() {
    fib[1] = 1, fib[2] = 2;
    int sum = 2;
    for (int i = 3; i <= MAX_N && fib[i - 1] + fib[i - 2] <= N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] & 1) continue;
        sum += fib[i];
    }
    printf("%d\n", sum);
    return 0;
}