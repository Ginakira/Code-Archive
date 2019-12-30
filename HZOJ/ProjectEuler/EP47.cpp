/************************************************************
    File Name : EP47.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 18:09:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j]++;
        }
    }
    return;
}

int main() {
    init();
    int ans = 0;
    for (int i = 1000; i < MAX_N; ++i) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; ++j) {
            flag = (prime[i + j] == 4);
        }
        if (!flag) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}