/************************************************************
    File Name : #518-金币.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 17:31:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, sum = 0;
    cin >> x;
    for (int i = 1; x > 0; ++i) {
        if (x >= i) {
            sum += i * i;
        } else {
            sum += i * x;
        }
        x -= i;
    }
    cout << sum << endl;
    return 0;
}