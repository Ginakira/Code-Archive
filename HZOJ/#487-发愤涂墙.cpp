/************************************************************
    File Name : #487-发愤涂墙.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/04 11:09:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 45
long long f[MAX_N + 5] = {0, 2, 2};

int main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; ++i) f[i] = f[i - 1] + f[i - 2];
    cout << f[n] << endl;
    return 0;
}