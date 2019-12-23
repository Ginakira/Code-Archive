/************************************************************
    File Name : EP20.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 20:36:31
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int ans[200];

int main() {
    ans[0] = 1, ans[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        for (int j = 1; j <= ans[0]; ++j) {
            ans[j] *= i;
        }
        for (int k = 1; k <= ans[0]; ++k) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; ++i) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}