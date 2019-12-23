/************************************************************
    File Name : EP37.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 19:58:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000000

int is_prime[MAXN + 5] = {1, 1, 0};
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

int is_val(int x) {
    int tmp = x;
    int dig = floor(log10(x)) + 1;
    for (int i = 0; i < dig - 1; ++i) {
        tmp /= 10;
        if (is_prime[tmp]) return 0;
    }
    tmp = x;
    int h = pow(10, dig - 1);
    for (int i = 0; i < dig - 1; ++i) {
        // tmp %= h;
        tmp -= tmp / h * h;
        h /= 10;
        if (is_prime[tmp]) return 0;
    }
    return 1;
}

int main() {
    init();
    long long sum = 0;
    int cnt = 0;
    for (int i = 5; i <= prime[0] && cnt < 11; ++i) {
        if (!is_val(prime[i])) continue;
        cout << prime[i] << endl;
        cnt++;
        sum += prime[i];
    }
    cout << endl << sum << endl;
    return 0;
}