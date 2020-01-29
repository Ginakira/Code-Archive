/************************************************************
    File Name : #500-数的计算.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 19:45:13
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

long long ans[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i >> 1; ++j) {
            ans[i] += ans[j];
        }
        ans[i]++;
    }
    cout << ans[n] << endl;
    return 0;
}