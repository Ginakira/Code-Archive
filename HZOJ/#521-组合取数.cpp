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
#include <vector>
using namespace std;
#define MAXN 2000000

int prime[MAXN + 5];
int is_prime[MAXN + 5];
int arr[35];
int n, r, ans;

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

void findCombinations(int n, int r, int begin, int sum, int cnt) {
    if (cnt == r) {
        ans += !is_prime[sum];
        return;
    }
    for (int i = begin; i < n - (r - cnt) + 1; ++i) {
        sum += arr[i];
        cnt++;
        findCombinations(n, r, i + 1, sum, cnt);
        sum -= arr[i];
        cnt--;
    }
    return;
}

int main() {
    init();
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> pre;
    findCombinations(n, r, 0, 0, 0);
    cout << ans << endl;
    return 0;
}