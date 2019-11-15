/************************************************************
    File Name : #37-统计满足条件数的个数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 11:28:40
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int m, n, cnt = 0;
    cin >> m >> n;
    for (int i = m; i <= n; ++i) {
        if (!(i % 2 == 0 && i % 5 == 0)) cnt++;
    }
    cout << cnt;
    return 0;
}