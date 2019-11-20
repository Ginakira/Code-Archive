/************************************************************
    File Name : #311-素数GCD对.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-17 15:38:40
************************************************************/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#define MAXN 10000010
using namespace std;

bool is_prime[MAXN];
int prime[MAXN], prime_cnt = 0;

void prime_init() {
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) prime[prime_cnt++] = i;
        for (int j = 0; j < prime_cnt && i * prime[j] < MAXN; ++j) {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j])) break;
        }
    }
    return;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    prime_init();
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (is_prime[gcd(i, j)]) ans++;
        }
    }
    string s = "hj";
    cout << ans << endl;
    return 0;
}