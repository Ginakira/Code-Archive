/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/25 19:43:37
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
#define MAX_N 1000000
LL arr[MAX_N + 5];
LL s[MAX_N + 5], f[MAX_N + 5];
LL n;

int main() {
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }
    LL c = s[n] / n;
    for (int i = 1; i <= n; ++i) {
        f[i] = s[i] - i * c;
    }
    sort(f + 1, f + n + 1);
    LL tf = f[(n + 1) >> 1], cost = 0;
    for (int i = 1; i <= n; ++i) {
        cost += abs(f[i] - tf);
    }
    cout << cost << endl;
    return 0;
}