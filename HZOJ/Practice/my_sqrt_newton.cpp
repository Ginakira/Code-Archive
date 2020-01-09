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

double f(double x, double n) { return x * x - n; }

double f_prime(double x) { return 2 * x; };

double my_sqrt(double n) {
    double x = 1.0;
    int cnt = 0;
    while (fabs(f(x, n)) > EPS) {
        x = x - f(x, n) / f_prime(x);
        cnt++;
    }
    printf("run %d steps\n", cnt);
    return x;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf", my_sqrt(x));
    return 0;
}