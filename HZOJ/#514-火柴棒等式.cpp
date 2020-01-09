/************************************************************
    File Name : #514-火柴棒等式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/04 21:14:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calc(int x) {
    if (x < 10) return cost[x];
    int ans = 0;
    for (int i = x; i; i /= 10) ans += cost[i % 10];
    return ans;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int a = 0; a <= 1000; ++a) {
        for (int b = a; b <= 1000; ++b) {
            int c = a + b;
            if (calc(a) + calc(b) + calc(c) - n + 4) continue;
            if (a != b)
                ans += 2;
            else
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}