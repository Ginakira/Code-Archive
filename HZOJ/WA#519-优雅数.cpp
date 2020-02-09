/************************************************************
    File Name : #519-优雅数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 17:45:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool is_elegent_number(long long a) {
    int cnt = 0, mark[10] = {0};
    while (a) {
        int num = a % 10;
        a /= 10;
        if (cnt > 2) return false;
        if (mark[num] == 0) cnt++;
        mark[num]++;
    }
    if (cnt != 2) return false;
    for (auto i : mark) {
        if (i == 1) return true;
    }
    return false;
}

int main() {
    long long l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (is_elegent_number(i)) cnt++;
    }
    cout << cnt;
    return 0;
}