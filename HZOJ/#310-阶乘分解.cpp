/************************************************************
    File Name : #310-阶乘分解.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 14:42:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int cnt[MAX_N + 5] = {0};

void init(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    init(n);
    for (int j = 1; j <= prime[0]; ++j) {
        long long tmp = prime[j], cnt = 0;
        while (tmp <= n) {
            cnt += n / tmp;
            tmp *= prime[j];
        }
        cout << prime[j] << ' ' << cnt << endl;
    }
    return 0;
}