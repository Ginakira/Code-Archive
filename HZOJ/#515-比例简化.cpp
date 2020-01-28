/************************************************************
    File Name : #515-比例简化.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 12:06:35
************************************************************/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    double a, b;
    int l;
    cin >> a >> b >> l;
    double ori_ratio = a / b, min_ratio = INT_MAX;
    int nume, deno;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (gcd(i, j) != 1) continue;
            double new_ratio = (double)i / j;
            if (new_ratio >= ori_ratio && new_ratio - ori_ratio < min_ratio) {
                min_ratio = new_ratio - ori_ratio;
                nume = i, deno = j;
            }
        }
    }
    cout << nume << ' ' << deno;
    return 0;
}