/************************************************************
    File Name : #572-有序表的最小和.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 10:36:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 400000
LL a[MAX_N + 5], b[MAX_N + 5];

priority_queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &b[i]);
        q.push(a[1] + b[i]);
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int sum = a[i] + b[j];
            if (sum < q.top()) {
                q.pop();
                q.push(sum);
            } else {
                break;
            }
        }
    }
    LL ans[MAX_N + 5], ind = n;
    while (!q.empty()) {
        ans[ind--] = q.top();
        q.pop();
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}