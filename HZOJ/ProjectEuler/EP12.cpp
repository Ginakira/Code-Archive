/************************************************************
    File Name : EP12.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/26 19:49:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 100000

int prime[MAX_N + 5] = {0};
int f[MAX_N + 5] = {0};    //存储因子个数
int cnt[MAX_N + 5] = {0};  //最小素因子幂次

void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {  //如果互素
                f[prime[j] * i] = f[prime[j]] * f[i];
                cnt[prime[j] * i] = 1;
            }
        }
    }
    return;
}

int main() {
    init();
    int n = 0, fac = 0;
    while (fac < 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1) / 2 << endl;
    return 0;
}