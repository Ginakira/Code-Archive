/************************************************************
    File Name : #54-炒鸡大整数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/13 10:02:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int factorial(int x) {
    if (x <= 2) return x;
    return x * factorial(x - 1);
}

int main() {
    cout << factorial(5) << endl;
    return 0;
}