/************************************************************
    File Name : 27.nullptr.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/02 20:06:37
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int f(int x) {
    cout << "Output int value : ";
    cout << x << endl;
    return 0;
}

int f(int *x) {
    cout << "Output address : ";
    cout << x << endl;
    return 0;
}

int main() {
    // cout << nullptr << endl;
    printf("%lld", (long long)nullptr);
    printf("%p", nullptr);
    cout << NULL << endl;
    int n = 123, *p = &n;
    f(n);
    f(p);
    f(nullptr);
    // f(NULL);
    return 0;
}