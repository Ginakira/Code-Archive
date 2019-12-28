/************************************************************
    File Name : EP16.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 15:52:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 400

int ans[MAX_N + 5] = {1, 1, 0};

int main() {
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= ans[0]; ++j) {
            ans[j] *= 1024;
        }
        for (int k = 1; k <= ans[0]; ++k) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            ans[k] %= 10;
            ans[0] += (k == ans[0]);
        }
    }
    int sum = 0;
    for (int i = 1; i <= ans[0]; ++i) sum += ans[i];
    cout << sum << endl;
    return 0;
}