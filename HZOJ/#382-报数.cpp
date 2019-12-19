/************************************************************
    File Name : #382-报数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 19:12:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    int cnt = 1;
    while (q.size() > 1) {
        if (cnt != m) {
            cnt++;
            q.push(q.front());
            q.pop();
        } else {
            q.pop();
            cnt = 1;
        }
    }
    cout << q.front();
    return 0;
}