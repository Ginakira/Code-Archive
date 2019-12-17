/************************************************************
    File Name : EP03.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 16:34:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define N 600851475143

int main() {
    long long ans = 0, M = N;
    long long i = 2;
    while (i * i <= M) {
        if (M % i == 0) ans = i;  // ans一定是素因子
        while (M % i == 0) M /= i;
        i += 1;
    }
    if (M > 1) ans = M;  //这一行代码是有必要的
    printf("%lld\n", ans);
    return 0;
}