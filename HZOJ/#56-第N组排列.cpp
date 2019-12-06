/************************************************************
    File Name : #56-第N组排列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 16:44:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[400000];

int main() {
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; ++i) {
        a[i] = i + 1;
    }
    for (int i = 0; i < y - 1 && next_permutation(a, a + x); ++i);
    for (int i = 0; i < x; ++i) {
        cout << a[i];
    }
    return 0;
}