/************************************************************
    File Name : EP07-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/17 18:51:19
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 200000

int prime[MAX_N + 5] = {0};

void init() {  //仅做标记
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return;
}

void init2() {
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
    }
    return;
}

int main() {
    init2();
    printf("%d\n", prime[10001]);
    return 0;
}