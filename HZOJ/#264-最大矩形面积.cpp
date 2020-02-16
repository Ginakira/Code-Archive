/************************************************************
    File Name : #264-最大矩形面积.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/16 20:11:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAXN 100000
typedef long long LL;

int h[MAXN + 5];
LL l[MAXN + 5], r[MAXN + 5];
int s[MAXN + 5], top = -1;

int main() {
    int n;
    cin >> n;
    h[0] = h[n + 1] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    s[++top] = 0;
    for (int i = 1; i <= n; ++i) {
        while (h[i] <= h[s[top]]) top--;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (h[i] <= h[s[top]]) top--;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, (r[i] - l[i] - 1) * h[i]);
    }
    cout << ans << endl;
    return 0;
}