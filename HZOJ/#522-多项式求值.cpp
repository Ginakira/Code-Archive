/************************************************************
    File Name : #522-多项式求值.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 19:05:59
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x, a, sum = 0;
    cin >> n >> x;
    for (int i = 0; i <= n; ++i) {
        cin >> a;
        sum += a * pow(x, i);
    }
    cout << sum << endl;
    return 0;
}