/************************************************************
    File Name : #517-三角形个数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/10 16:04:47
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int a = 1; a <= n - 2; ++a) {
        for (int b = a; b <= n - 2; ++b) {
            int c = n - a - b;
            if (a + b > c && c >= b) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}