/************************************************************
    File Name : #583-字符串处理.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/19 11:36:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
string str;
int ans;

void func(int l, int r) {
    for (int i = 0; 1; ++i) {
        if (l - i < 0 || str[l - i] != str[r + i]) break;
        ans++;
    }
}

void solve() {
    ans = 0;
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        func(i, i);
        func(i, i + 1);
    }
    cout << ans << endl;
}

int main() {
    while (cin >> str) {
        solve();
    }
    return 0;
}