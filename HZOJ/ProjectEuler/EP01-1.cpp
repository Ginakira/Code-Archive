/************************************************************
    File Name : EP01.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 14:54:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int is_val(int n) {
    if (n % 3 == 0 || n % 5 == 0) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; ++i) {
        if (!is_val(i)) continue;
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}