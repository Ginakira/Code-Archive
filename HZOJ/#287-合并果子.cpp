/************************************************************
    File Name : #287-合并果子.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/13 22:39:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int n, ans = 0, tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        q.push(tmp);
    }
    while (q.size() > 1) {
        tmp = 0;
        tmp += q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        ans += tmp;
        q.push(tmp);
    }
    cout << ans << endl;
    return 0;
}