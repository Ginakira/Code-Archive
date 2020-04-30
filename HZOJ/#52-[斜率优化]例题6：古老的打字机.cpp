/************************************************************
    File Name : #52-例题6：古老的打字机.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/30 20:45:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000000
typedef long long LL;

inline LL SQ(LL x) { return x * x; }

LL c[MAX_N + 5], sum[MAX_N + 5];
LL f[MAX_N + 5], dp[MAX_N + 5];
LL q[MAX_N + 5], head = 0, tail = 0;
int n, M;

void set(int i, int j) {
    dp[i] = dp[j] + SQ(sum[i] - sum[j]) + M;
    f[i] = dp[i] + SQ(sum[i]);
}

double slope(int i, int j) { return 1.0 * (f[i] - f[j]) / (sum[i] - sum[j]); }

int main() {
    cin >> n >> M;
    c[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        sum[i] = sum[i - 1] + c[i];
    }
    q[tail++] = 0;
    for (int i = 1; i <= n; ++i) {
        while (tail - head >= 2 && slope(q[head], q[head + 1]) <= 2 * sum[i])
            ++head;
        set(i, q[head]);
        while (tail - head >= 2 &&
               slope(q[tail - 1], q[tail - 2]) > slope(q[tail - 1], i))
            --tail;
        q[tail++] = i;
    }
    cout << dp[n] << endl;

    return 0;
}