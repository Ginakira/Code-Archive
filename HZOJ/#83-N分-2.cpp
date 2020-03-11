/************************************************************
    File Name : #83-N分.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 20:02:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, num[10], cnt, ans;

void output() {
    for (int i = 0; i < m; ++i) {
        i&& cout << "+";
        cout << num[i];
    }
    cout << endl;
    return;
}

void func(int s, int left_num, int left_cnt) {
    if (!left_cnt) {
        ans += (left_num == 0);
        if (!left_num) output();
        return;
    }
    for (int i = s; i <= left_num; ++i) {
        num[cnt++] = i;
        func(i, left_num - i, left_cnt - 1);
        cnt--;
    }
    return;
}

int main() {
    cin >> n >> m;
    func(1, n, m);
    cout << ans << endl;
    return 0;
}