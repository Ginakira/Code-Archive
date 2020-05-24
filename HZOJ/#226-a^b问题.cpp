/************************************************************
    File Name : #226-a^b问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/24 20:07:56
************************************************************/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long qpow(int a, int b, int MOD) {
    long long ans = 1, base = a;
    while (b) {
        if (b & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << qpow(a, b, p) << endl;
    return 0;
}