/************************************************************
    File Name : EP24.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 19:18:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 10

int fac[MAX_N];
int num[MAX_N];  //标记数字是否被用过 0为用过

void init(int n) {
    fac[0] = 1;
    num[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = i * fac[i - 1];
        num[i] = 1;
    }
    return;
}

int get_num(int k, int n, int &x) {
    int step = k / n;  //跳跃的步数
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    //等价于
    /* for (int t = 0; t <= step;) {
        if (num[x]) t++;
        x++;
    }
    x--; */
    k %= n;
    num[x] = 0;
    return k;
}

int main() {
    init(9);
    int k = 1000000 - 1;  //剩余的跳跃状态数
    for (int i = MAX_N; i > 0; --i) {
        int x;  //最终跳到的数字
        k = get_num(k, fac[i - 1], x);
        cout << x;
    }
    cout << endl;
    return 0;
}