/************************************************************
    File Name : EP46.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 16:09:49
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

int is_sqrt(int n) { return 2 * n * n; }

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

bool binary_search(int (*func)(int), int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return true;
    if (func(mid) < x)
        l = mid + 1;
    else
        r = mid - 1;
    return binary_search(func, l, r, x);
}

bool check(int n) {
    for (int j = 1; j <= prime[0] && prime[j] < n; ++j) {
        if (binary_search(is_sqrt, 1, n - prime[j], n - prime[j])) return true;
    }
    return false;
}

int main() {
    init();
    int ans = 0;
    for (int i = 9; i <= MAX_N; i += 2) {
        if (!is_prime[i]) continue;
        if (check(i)) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}