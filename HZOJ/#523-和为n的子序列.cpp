/************************************************************
    File Name : #523-和为n的子序列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/27 20:29:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, l = 1, r = 1;
    cin >> n;
    int now = 1;
    while (now != n) {
        if (now < n)
            r++, now += r;
        else
            now -= l, l++;
    }
    for (int i = l; i <= r; ++i) {
        i == l || cout << ' ';
        cout << i;
    }
    cout << endl;
    return 0;
}