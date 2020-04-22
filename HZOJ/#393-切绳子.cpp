/************************************************************
    File Name : #393-切绳子.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/22 19:22:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define EPS 0.001

int n, k;
double arr[100005], max_len;

int calc(double mid) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += arr[i] / mid;
    }
    return cnt;
}

double func() {
    double l = 0, r = max_len;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        int x = calc(mid);
        if (x >= k)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        max_len = max(max_len, arr[i]);
    }
    double ans = func();
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return 0;
}