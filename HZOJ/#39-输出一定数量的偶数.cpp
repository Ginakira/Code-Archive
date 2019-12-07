/************************************************************
    File Name : #39-输出一定数量的偶数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-06 23:35:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int begin, n, cnt = 0;
    cin >> begin >> n;
    for (int i = begin; cnt < n; ++i) {
        if (!(i & 1) && i >= 0) {
            cout << i << endl;
            cnt++;
        }
    }
    return 0;
}