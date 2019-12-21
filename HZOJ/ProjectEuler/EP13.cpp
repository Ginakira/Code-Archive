/************************************************************
    File Name : EP13.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 15:58:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 52

char str[MAXN + 5] = {0};
int ans[MAXN + 5] = {0};

int main() {
    while (~scanf("%s", str)) {
        int len = strlen(str);
        if (len > ans[0]) ans[0] = len;  // ans[0]存储数字位数
        for (int i = 0; i < len; ++i) {
            ans[len - i] += str[i] - '0';
        }
        for (int i = 1; i <= ans[0]; ++i) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]); // 如果在最高位产生进位 则位数+1
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; --i) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}