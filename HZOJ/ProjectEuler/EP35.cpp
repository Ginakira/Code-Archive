/************************************************************
    File Name : EP35.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 18:57:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000000

int is_prime[MAXN + 5];
int prime[MAXN + 5];

void init() {
    for (int i = 2; i <= MAXN; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAXN) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int is_val(int a) {
    int dig = floor(log10(a)) + 1;
    for (int i = 0; i < dig - 1; ++i) {
        int temp = a % 10;
        a /= 10;
        a += temp * pow(10, dig - 1);
        if (is_prime[a]) return 0;
    }
    return 1;
}

int main() {
    init();
    int cnt = 0;
    for (int i = 1; i <= prime[0]; ++i) {
        if (!is_val(prime[i])) continue;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}