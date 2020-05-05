/************************************************************
    File Name : #492-回文拆分.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/05 17:14:20
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 26

int f[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            f[i] = f[i - 1];
        } else {
            f[i] = f[i - 1] * 2 + 1;
        }
    }
    cout << f[n] << endl;
    return 0;
}