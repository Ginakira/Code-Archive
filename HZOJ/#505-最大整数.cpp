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

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (auto &i : arr) cin >> i;
    sort(arr, arr + n);
    for (auto i : arr) cout << i << endl;
    return 0;
}