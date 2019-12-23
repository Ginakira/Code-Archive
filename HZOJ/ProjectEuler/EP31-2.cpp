/************************************************************
    File Name : EP31-2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 15:01:26
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
int f[2][MAX_M + 5];

int main() {
    for (int k = 0; k < MAX_N; ++k) {
        int i = k % 2;
        f[i][0] = 1;
        for (int j = 1; j <= MAX_M; ++j) {
            f[i][j] = 0;
            f[i][j] += f[i ^ 1][j];
            if (j >= w[k]) f[i][j] += f[i][j - w[k]];
        }
    }
    printf("%d\n", f[(MAX_N - 1) % 2][MAX_M]);
    return 0;
}