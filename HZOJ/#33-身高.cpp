/************************************************************
    File Name : #33-身高.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 11:22:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double m, n;
    int p;
    cin >> m >> n >> p;
    cout << setiosflags(ios::fixed) << setprecision(2);
    if(p == 1) {
        cout << (m + n) * 1.087 / 2;
    } else {
        cout << (m * 0.973 + n) / 2;
    }
    return 0;
}