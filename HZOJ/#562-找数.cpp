/************************************************************
    File Name : #562-找数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 20:21:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ans, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (i == 0) {
            ans = tmp;
        } else
            ans ^= tmp;
    }
    cout << ans << endl;
    return 0;
}