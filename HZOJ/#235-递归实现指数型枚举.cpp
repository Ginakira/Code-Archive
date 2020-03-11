/************************************************************
    File Name : #235-递归实现指数型枚举.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/03/11 19:06:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, num[15], cnt;

void output() {
    for (int i = 0; i < cnt; ++i) {
        i&& cout << " ";
        cout << num[i];
    }
    cout << endl;
    return;
}

void func(int s) {
    for (int i = s; i <= n; ++i) {
        num[cnt++] = i;
        output();
        func(i + 1);  // 深搜
        cnt--;        // 回溯
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}