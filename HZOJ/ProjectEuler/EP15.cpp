/************************************************************
    File Name : EP15.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 15:39:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long m = 40, n = 20, ans = 1;
    while (m != 20 || n) {
        if (m != 20) ans *= (m--);
        if (n != 0 && ans % n == 0) ans /= (n--);
    }
    cout << ans << endl;
    return 0;
}