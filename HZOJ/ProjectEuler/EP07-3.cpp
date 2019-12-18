/************************************************************
    File Name : EP07-3
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/17 20:46:36
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

void init() {
    for (int i = 2; i <= MAX_N; ++i) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}