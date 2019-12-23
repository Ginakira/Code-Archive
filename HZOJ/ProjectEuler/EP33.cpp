/************************************************************
    File Name : EP33.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 18:05:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int is_val(int x, int y) {
    int x1 = x / 10, x2 = x % 10;
    int y1 = y / 10, y2 = y % 10;
    if (!x2 || !y2) return 0;
    if (x1 == y1 && x2 * y == y2 * x) return 1;
    if (x1 == y2 && x2 * y == y1 * x) return 1;
    if (x2 == y1 && x1 * y == y2 * x) return 1;
    if (x2 == y2 && x1 * y == y1 * x) return 1;
    return 0;
}

int main() {
    int x = 1, y = 1, c = 1;
    for (int i = 10; i <= 98; ++i) {
        for (int j = i + 1; j <= 99; ++j) {
            if (!is_val(i, j)) continue;
            cout << i << ' ' << j << endl;
            x *= i, y *= j;
            c = gcd(x, y);
            x /= c, y /= c;
        }
    }
    cout << y << endl;
    return 0;
}