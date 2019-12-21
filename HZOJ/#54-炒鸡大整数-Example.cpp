/************************************************************
    File Name : #54-炒鸡大整数-Example.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 18:32:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1500

int ans[MAXN + 5] = {0};
int res[MAXN + 5] = {0};

void large_plus(int *arr, int val) {
    for (int i = 1; i <= arr[0]; ++i) {
        arr[i] *= i;
    }
    for (int j = 1; j <= arr[0]; ++j) {
        if (arr[j] < 10) continue;
        arr[j + 1] += arr[j] / 10;
        arr[j] %= 10;
        arr[0] += (j == arr[0]);
    }
}

void solve(int x) {
    memset(ans, 0, sizeof(ans));
    ans[0] = 1, ans[1] = 1;
    for (int i = 1; i <= x; ++i) {
        large_plus(ans, i);
    }
    memset(res, 0, sizeof(res));
    res[0] = 1, res[1] = 1;
    for (int i = 1; i <= ans[0]; ++i) {
        if (!ans[i]) continue;
        large_plus(res, ans[i]);
    }
    for (int i = res[0]; i > 0; --i) {
        printf("%d", res[i]);
    }
    printf("\n");
    return;
}

int main() {
    int x;
    while (~scanf("%d", &x)) solve(x);
    return 0;
}