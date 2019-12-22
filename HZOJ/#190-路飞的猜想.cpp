/************************************************************
    File Name : #190-路飞的猜想.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 19:42:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 8000000

int is_prime[MAXN + 5] = {0};
int prime[MAXN + 5] = {0};

void init(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    int n, ans = 0;
    cin >> n;
    init(n);
    for (int i = 2; i * 2 <= n; ++i) {
        if (!is_prime[i] && !is_prime[n - i]) ans++;
    }
    cout << ans << endl;
    return 0;
}