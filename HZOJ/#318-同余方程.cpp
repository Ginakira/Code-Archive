/************************************************************
    File Name : #318-同余方程.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-08 16:04:18
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LL long long

void ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    LL xx, yy;
    ex_gcd(b, a % b, xx, yy);
    x = yy;
    y = xx - a / b * yy;
    return;
}

int main() {
    LL a, b, x, y;
    while (cin >> a >> b) {
        ex_gcd(a, b, x, y);
        LL t = b;
        cout << (x % t + t) % t << endl;
    }
    return 0;
}