/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/27 15:52:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
typedef long long LL;
LL arr[MAX_N + 5];
int s[MAX_N + 5], top = -1;
int l[MAX_N + 5], r[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    arr[0] = arr[n + 1] = -1;
    s[++top] = 0;
    for (int i = 1; i <= n; ++i) {
        while (arr[s[top]] >= arr[i]) top--;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i > 0; --i) {
        while (arr[s[top]] >= arr[i]) top--;
        r[i] = s[top];
        s[++top] = i;
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, (r[i] - l[i] - 1) * arr[i]);
    }
    cout << ans << endl;
    return 0;
}