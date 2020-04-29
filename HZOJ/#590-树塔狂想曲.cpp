/************************************************************
    File Name : #590-树塔狂想曲.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 20:46:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 1000

// 从上往下算一遍，从下往上算一遍
// 这样我们将某个位置对两个数组相加再减去其本身，那就是经过这个点路径的最大值
// 然后我们可以求出每一行经过点的路径的最大值 以及次大值
// 如果我们ban掉的是最大值的那个点 那我们输出次大值 如果不是则输出最大值

int n, m, num[MAX_N + 5][MAX_N + 5];
int down[MAX_N + 5][MAX_N + 5], up[MAX_N + 5][MAX_N + 5];
int mmax[MAX_N + 5], mmax_ind[MAX_N + 5], mmax2[MAX_N + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    //  Up to down
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            down[i][j] = max(down[i - 1][j - 1], down[i - 1][j]) + num[i][j];
        }
    }

    // Down to up
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= i; ++j) {
            up[i][j] = max(up[i + 1][j + 1], up[i + 1][j]) + num[i][j];
        }
    }

    // Every rows max_val and second biggest val
    for (int i = 2; i <= n; ++i) {
        int ind1 = 0, ind1_max = 0, ind2_max = 0;
        for (int j = 1; j <= i; ++j) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > ind1_max) {
                ind1_max = t;
                ind1 = j;
            }
        }
        for (int j = 1; j <= i; ++j) {
            int t = down[i][j] + up[i][j] - num[i][j];
            if (t > ind2_max && j != ind1) {
                ind2_max = t;
            }
        }
        mmax[i] = ind1_max;
        mmax_ind[i] = ind1;
        mmax2[i] = ind2_max;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
            continue;
        }
        if (mmax_ind[a] == b) {
            printf("%d\n", mmax2[a]);
        } else {
            printf("%d\n", mmax[a]);
        }
    }
    return 0;
}