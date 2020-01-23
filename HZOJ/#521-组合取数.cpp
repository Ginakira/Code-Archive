/************************************************************
    File Name : #521-组合取数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/13 16:02:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000000

int prime[MAXN + 5];
int is_prime[MAXN + 5];
int arr[35];

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAXN) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    init();
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i + r < n; ++i) {
    }
    cout << ans << endl;
    return 0;
}