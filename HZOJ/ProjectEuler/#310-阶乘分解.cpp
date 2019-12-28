/************************************************************
    File Name : #310-阶乘分解.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 14:06:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000000
int is_prime[MAX_N + 5] = {1, 1, 0};
int prime[MAX_N + 5] = {0};
int cnt[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    int max_fac = 2;
    for (int i = 2; i <= n; ++i) {
        int num = i;
        for (int j = 1; j <= prime[0] && prime[j] <= num; ++j) {
            if (num % prime[j] == 0) max_fac = max(max_fac, prime[j]);
            while (num % prime[j] == 0) {
                cnt[prime[j]]++;
                num /= prime[j];
            }
        }
    }
    for (int k = 1; k <= prime[0] && prime[k] <= max_fac; ++k) {
        printf("%d %d\n", prime[k], cnt[prime[k]]);
    }
    return 0;
}