/************************************************************
    File Name : #491-核电站.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/05 00:11:12
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 50
long long f[MAX_N + 5] = {1, 2};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        if (i < m)
            f[i] = f[i - 1] * 2;
        else if (i == m)
            f[i] = f[i - 1] * 2 - 1;
        else
            f[i] = f[i - 1] * 2 - f[i - m - 1];
    }
    cout << f[n] << endl;
    return 0;
}