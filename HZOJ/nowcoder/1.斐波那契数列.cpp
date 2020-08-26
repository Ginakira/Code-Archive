/************************************************************
    File Name : 1.斐波那契数列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/26 16:04:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
    LL n;
    cin >> n;
    LL a = 0, b = 1, c = 1;
    for (int i = 1; i <= n; ++i) {
        c = a + b;
        a = b, b = c;
    }
    cout << c << endl;

    return 0;
}