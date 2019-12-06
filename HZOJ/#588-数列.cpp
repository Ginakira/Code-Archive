/************************************************************
    File Name : #588-数列.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 16:26:30
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string pre = "1", now = "";
    cin >> n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        now = "";
        int cnt = 1;
        string num;
        num.push_back(pre[0]);
        for (int j = 0; j < pre.length(); ++j) {
            if (pre[j] != pre[j + 1]) {
                now += to_string(cnt) + num;
                cnt = 1;
                num = "";
                num.push_back(pre[j + 1]);
            } else {
                cnt++;
            }
        }
        pre = now;
    }
    cout << now << endl;
    return 0;
}