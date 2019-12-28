/************************************************************
    File Name : EP09.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/26 19:02:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int ans = 0;
    for (int n = 1; n <= 33; ++n) {
        for (int m = n + 1; m * m + n * n <= 1000; ++m) {
            if (gcd(m, n) - 1) continue;
            int a = 2 * m * n;
            int b = m * m - n * n;
            int c = m * m + n * n;
            //某一个整数倍相加之和为1000
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + b + c);
                ans = k * a * k * b * k * c;
            }
            if (ans) break;
        }
        if (ans) break;
    }
    cout << ans << endl;
    return 0;
}