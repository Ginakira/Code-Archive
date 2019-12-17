/************************************************************
    File Name : EP02-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 15:47:01
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
    int sum = 0;
    int a = 0, b = 1;
    while (a + b <= N) {
        b = a + b;
        a = b - a;
        if (b & 1) continue;
        sum += b;
    }
    printf("%d\n", sum);
    return 0;
}