/************************************************************
    File Name : EP31-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 15:41:26
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 8
#define MAX_M 200

int w[MAX_N + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[MAX_M + 5];

int main() {
    f[0] = 1;
    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 1; j <= MAX_M; ++j) {
            if (j >= w[i]) f[j] += f[j - w[i]];
        }
    }
    printf("%d\n", f[MAX_M]);
    return 0;
}