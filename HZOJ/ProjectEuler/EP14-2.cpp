/************************************************************
    File Name : EP14-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 14:30:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LL long long
#define MAXN 1000000

int keep[MAXN + 5] = {0};

LL get_len(LL n) {
    if (n == 1) return 1;
    if (n <= MAXN && keep[n]) return keep[n];
    LL ret = 0;
    if (!(n & 1))
        ret = get_len(n >> 1) + 1;
    else
        ret = get_len(3 * n + 1) + 1;
    if (n <= MAXN) keep[n] = ret;
    return ret;
}

int main() {
    int ans = 0, len = 0;
    for (int i = 1; i < MAXN; ++i) {
        int tmp = get_len(i);
        if (tmp > len) {
            ans = i;
            len = tmp;
        }
    }
    printf("num = %d, len = %d\n", ans, len);
    return 0;
}