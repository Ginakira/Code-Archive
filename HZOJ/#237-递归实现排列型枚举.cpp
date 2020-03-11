/************************************************************
    File Name : #237-递归实现排列型枚举.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 19:33:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans[10], cnt;
bool mark[15] = {0};

void output() {
    for (int i = 0; i < n; ++i) {
        i&& cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return;
}

void func(int left) {
    if (!left) {
        output();
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (mark[i]) continue;
        ans[cnt++] = i, mark[i] = 1;
        func(left - 1);
        cnt--, mark[i] = 0;
    }
    return;
}

int main() {
    cin >> n;
    func(n);
    return 0;
}