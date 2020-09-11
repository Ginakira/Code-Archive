/************************************************************
    File Name : 1-4.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/09 08:50:57
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500

int main() {
    float ans[MAX_N + 5] = {0};
    ans[0] = 0.1823;
    for (int i = 1; i <= 9; ++i) {
        ans[i] = 1.0 / i - 5 * ans[i - 1];
    }
    // WAY 2
    float ans2[MAX_N + 5] = {0};
    ans[9] = 0.0183;
    for (int i = 8; i >= 0; --i) {
        ans2[i] = 1.0 / (5 * i) - ans2[i + 1] / 5.0;
    }
    // PRINT
    for (int i = 0; i <= 9; ++i) {
        cout << "ans[" << i << "] = " << ans[i];
        cout << "\t"
             << "ans2[" << i << "] = " << ans2[i] << endl;
    }
    return 0;
}