/************************************************************
    File Name : EP36.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/15 20:48:06
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int is_palindrome(int n, int base) {
    int x = n, tmp = 0;
    while (x) {
        tmp = tmp * base + x % base;
        x /= base;
    }
    return tmp == n;
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 1000000; ++i) {
        if (is_palindrome(i, 10) && is_palindrome(i, 2)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}