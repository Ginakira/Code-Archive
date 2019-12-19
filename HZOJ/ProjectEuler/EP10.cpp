/************************************************************
    File Name : EP10.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/19 18:48:11
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

void linear_prime() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    linear_prime();
    long long ans = 0;
    for (int i = 1; i <= prime[0]; ++i) ans += prime[i];
    printf("%d\n", prime[prime[0]]);
    printf("%lld\n", ans);
    return 0;
}