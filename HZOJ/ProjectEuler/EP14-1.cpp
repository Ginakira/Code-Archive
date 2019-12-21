/************************************************************
    File Name : EP14.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 14:11:31
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

LL get_len(LL n) {
    if (n == 1) return 1;
    if (!(n & 1)) return get_len(n >> 1) + 1;
    return get_len(3 * n + 1) + 1;
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