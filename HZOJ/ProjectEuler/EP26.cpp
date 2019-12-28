/************************************************************
    File Name : EP26.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/28 20:35:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1000

int r_len[MAX_N + 5];

int get_len(int d) {
    int r = 1, t = 1;
    r_len[r] = 1;
    while (r) {
        r *= 10;
        r %= d;
        t++;
        if (r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;  //可以被整除
}

int main() {
    int d = 0, len = -1;
    for (int i = 2; i < MAX_N; ++i) {
        memset(r_len, 0, sizeof(r_len));
        int tmp = get_len(i);
        if (len < tmp) {
            len = tmp;
            d = i;
        }
    }
    cout << d << endl;
    cout << len << endl;
    return 0;
}