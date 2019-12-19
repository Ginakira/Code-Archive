/************************************************************
    File Name : EP08.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/19 18:09:49
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

char num[MAX_N + 5];

int main() {
    int len = 0;
    while (~scanf("%s", num + len)) len = strlen(num);
    long long ans = 0, p = 1, zero = 0;
    for (int i = 0; num[i]; ++i) {
        num[i] -= '0';
        if (num[i])
            p *= num[i];
        else
            zero++;
        if (i < 13) continue;
        if (num[i - 13])
            p /= num[i - 13];
        else
            zero--;
        if (zero == 0 && p > ans) ans = p;
    }
    printf("%lld\n", ans);
    return 0;
}