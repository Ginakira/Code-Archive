/************************************************************
    File Name : EP05.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/17 18:22:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int ans = 1;
    for (int i = 1; i <= 20; ++i) {
        if (ans % i == 0) continue;
        ans *= i / gcd(ans, i);
    }
    cout << ans << endl;
    return 0;
}