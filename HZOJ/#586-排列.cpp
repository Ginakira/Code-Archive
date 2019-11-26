/************************************************************
    File Name : #586-排列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 20:01:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool mark[10];

void mark_num(int num) {
    while (num != 0) {
        mark[num % 10] = true;
        num /= 10;
    }
    return;
}

int cal() {
    int cnt = 0;
    for (int i = 1; i < 10; ++i) {
        if (mark[i]) cnt++;
    }
    return cnt;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int tmp = gcd(gcd(x, y), z);
    x /= tmp, y /= tmp, z /= tmp;
    for (int a = 123; a < 999; ++a) {
        fill(mark, mark + 10, false);
        int b = a / x * y, c = a / x * z;
        if (b >= 1000 || c >= 1000 || a % x != 0) continue;
        mark_num(a);
        mark_num(b);
        mark_num(c);
        if (cal() == 9) {
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }
    return 0;
}