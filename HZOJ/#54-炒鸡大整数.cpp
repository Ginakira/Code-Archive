/************************************************************
    File Name : #54-炒鸡大整数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 18:02:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1500
void solve(int x) {
    int ans[MAXN + 5] = {0};
    int sum[MAXN + 5] = {0};
    ans[0] = 1, ans[1] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= ans[0]; ++j) {
            ans[j] *= i;
        }
        for (int k = 1; k <= ans[0]; ++k) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (ans[0] == k);
        }
    }
    sum[0] = 1, sum[1] = 1;
    for (int i = 1; i <= ans[0]; ++i) {
        if (ans[i]) {
            for (int j = 1; j <= sum[0]; ++j) {
                sum[j] *= ans[i];
            }
            for (int k = 1; k <= ans[0]; ++k) {
                if (sum[k] < 10) continue;
                sum[k + 1] += sum[k] / 10;
                sum[k] %= 10;
                sum[0] += (sum[0] == k);
            }
        }
    }
    for (int i = sum[0]; i > 0; --i) {
        printf("%d", sum[i]);
    }
    printf("\n");
    return;
}

int main() {
    int x;
    while (~scanf("%d", &x)) solve(x);
    return 0;
}