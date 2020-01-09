/************************************************************
    File Name : my_sqrt_binary.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/07 19:22:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define EPS 1e-7

double my_sqrt(double x) {
    double l = 0, r = (x <= 1.0 ? 1.0 : x);
    // while (r - l > EPS) {
    for (int i = 0; i < 10000; ++i) {
        double mid = (l + r) / 2.0;
        if (mid * mid <= x)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf", my_sqrt(x));
    return 0;
}