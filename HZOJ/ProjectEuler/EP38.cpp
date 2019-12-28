/************************************************************
    File Name : EP38.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/24 18:22:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int digits(long long n) {
    if (!n) return 1;
    return floor(log10(n)) + 1;
}

int calc(int x) {
    long long n = 1, ans = 0;
    while (digits(ans) < 9) {
        ans *= pow(10, digits(ans * n));
        ans += x * n;
        n++;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {1, 0};
    int tmp = ans;
    while (tmp) {
        if (num[tmp % 10]) return 0;
        num[tmp % 10] += 1;
        tmp /= 10;
    }
    return ans;
}

int main() {
    long long ans = 0;
    for (int i = 1; i < 10000; ++i) {
        int tmp = calc(i);
        if (tmp > ans) ans = tmp;
    }
    printf("%lld", ans);
    return 0;
}