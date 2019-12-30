/************************************************************
    File Name : EP39.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 15:08:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

int cnt[MAX_N + 5] = {0};

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    for (int n = 1; n <= 32; ++n) {
        for (int m = n + 1; m <= 32; ++m) {
            if (gcd(m, n) - 1) continue;
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            for (int p = a + b + c; p <= 1000; p += a + b + c) {
                cnt[p]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        if (cnt[i] > cnt[ans]) ans = i;
    }
    cout << ans << endl;
    return 0;
}