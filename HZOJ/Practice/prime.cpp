/************************************************************
    File Name : prime.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/08 20:51:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

int prime[MAX_N + 5] = {0};

void init_prime() {
    // 1为合数 0为素数
    prime[0] = 1, prime[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}

int main() {
    int n;
    init_prime();
    while (~scanf("%d", &n)) {
        printf("%s\n", prime[n] ? "NOT PRIME" : "IS PRIME");
    }
    return 0;
}