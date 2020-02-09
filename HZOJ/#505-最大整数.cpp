/************************************************************
    File Name : #505-最大整数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/08 23:08:12
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 100000

bool cmp(string a, string b) {
    string c = a + b, d = b + a;
    return c > d;
}

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (auto &i : arr) cin >> i;
    sort(arr, arr + n, cmp);
    for (auto i : arr) cout << i;
    return 0;
}