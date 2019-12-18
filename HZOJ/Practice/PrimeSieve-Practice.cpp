/************************************************************
    File Name : Prime-Practice.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/17 19:54:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
//求某数最小素因子
void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
}

//求某数最大素因子
void init2() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            // if (prime[j]) continue;
            prime[j] = i;
        }
    }
}

int main() {
    init();
    int num;
    while (~scanf("%d", &num)) {
        printf("Number:%d  minPF:%d  maxPF:%d\n", num, prime[num], 0);
    }
    return 0;
}