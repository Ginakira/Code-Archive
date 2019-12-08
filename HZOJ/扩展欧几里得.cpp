/************************************************************
    File Name : 扩展欧几里得.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-08 16:24:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int ex_gcd(int a, int b, int &x, int &y) {
        if (!b) {
            x = 1, y = 0;
            return a;
        }
        int xx, yy, ret = ex_gcd(b, a % b, xx, yy);
        x = yy;
        y = xx - a / b * yy;
        return ret;
    }

    int main() {
        int a, b, x, y;
        while (cin >> a >> b) {
            printf("ex_gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, x, y));
            printf("%d * %d + %d * %d = %d\n", a, x, b, y, ex_gcd(a, b, x, y));
        }
        return 0;
    }
    return 0;
}