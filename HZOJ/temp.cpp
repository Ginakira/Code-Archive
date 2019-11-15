/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-14 14:48:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    double a;
    while(cin >> a) {
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << fabs(a) << endl;
    }
    return 0;
}