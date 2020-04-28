/************************************************************
    File Name : #264-最大矩形面积.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/28 20:46:26
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
typedef long long LL;

LL a[MAX_N + 5];
int s[MAX_N + 5], top = -1;
int l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[n + 1] = -1;
    s[top = 0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[s[top]] >= a[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    s[top = 0] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (a[s[top]] >= a[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}