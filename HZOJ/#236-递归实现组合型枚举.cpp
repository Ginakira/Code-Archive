/************************************************************
    File Name : #236-递归实现组合型枚举.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 19:25:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, ans[15], cnt;

void output() {
    for (int i = 0; i < m; ++i) {
        i&& cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return;
}

void dfs(int s) {
    for (int i = s; i <= n; ++i) {
        ans[cnt++] = i;
        if (cnt == m) output();
        dfs(i + 1);
        cnt--;
    }
    return;
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}