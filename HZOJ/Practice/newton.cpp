/************************************************************
    File Name : newton.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/10 20:20:49
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define EPSL 1e-6
double F(double x) { return x * x - 2; }

double f(double x) {  // F导
    return 2 * x;
}

double newton(double (*F)(double), double (*f)(double)) {
    double x = 1.0;
    while (fabs(F(x)) > EPSL) {
        x -= F(x) / f(x);
    }
    return x;
}

int main() {
    double x = newton(F, f);
    printf("%lf\n", x);
    printf("%lf * %lf - 2 = %lf\n", x, x, x * x - 2);
    return 0;
}