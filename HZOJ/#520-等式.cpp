/************************************************************
    File Name : #520-等式.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/09 19:14:29
************************************************************/
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define LL long long

int main() {
    LL a;
    cin >> a;
    for (LL n = a + 1; n < INT_MAX; ++n) {
        for (LL k = a; k < n; ++k) {
            if (k * (k - 1) == (n + k + 1) * (n - k)) {
                cout << k << ' ' << n << endl;
                return 0;
            }
        }
    }
    return 0;
}