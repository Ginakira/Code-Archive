/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 08:38:49
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 200000

int prime[MAXN + 5] = {0};

void prime_init() {
    for (int i = 2; i * i <= MAXN; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAXN; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
    }
    return;
}

void linear_init() {
    for (int i = 2; i <= MAXN; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAXN) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {与知道内容相似度超过85%！
    linear_init();
    printf("%d prime numbers, answer: %d\n", prime[0], prime[10001]);
    return 0;
}