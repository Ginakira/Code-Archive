/************************************************************
    File Name : EP24-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 20:13:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num[10];
    for (int i = 0; i < 10; ++i) num[i] = i;
    int k = 1000000 - 1;
    while (k--) {
        next_permutation(num, num + 10);
    };
    for (int i = 0; i < 10; ++i) cout << num[i];
    return 0;
}