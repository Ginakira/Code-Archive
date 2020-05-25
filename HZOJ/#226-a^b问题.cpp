/************************************************************
    File Name : #226-a^b问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/25 10:32:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

LL quick_mod(LL a, LL b, LL p) {
    LL tmp = a, ans = 1;
    while (b) {
        if (b & 1) ans = ans * tmp % p;
        tmp = tmp * tmp % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    LL a, b, p;
    cin >> a >> b >> p;
    cout << quick_mod(a, b, p) << endl;
    return 0;
}