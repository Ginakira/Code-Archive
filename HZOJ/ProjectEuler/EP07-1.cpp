/************************************************************
    File Name : EP07.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/17 18:43:04
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#define LL long long
using namespace std;

bool is_prime(LL x) {
    for (LL i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    LL i;
    for (i = 2; cnt < 10001; ++i) {
        if (is_prime(i)) cnt++;
    }
    cout << i - 1 << endl;
    return 0;
}