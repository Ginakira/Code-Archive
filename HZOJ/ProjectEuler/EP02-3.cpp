/************************************************************
    File Name : EP02-3.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 16:03:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define N 4000000

int main() {
    int fib[3] = {0, 1};
    int sum = 0, n = 2;
    while (fib[(n - 1) % 3] + fib[(n - 2) % 3] <= N) {
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
        ++n;
    }
    printf("%d\n", sum);
    return 0;
}