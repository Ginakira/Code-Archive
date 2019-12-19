/************************************************************
    File Name : #384-敲七.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 19:33:59
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

bool is_seven(int x) {
    if (x % 7 == 0) return true;
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    for (int i = 1; i <= n; ++i) q.push(i);
    for (int i = 0; i < x - 1; ++i) {
        q.push(q.front());
        q.pop();
    }
    while (q.size() > 1) {
        if (!is_seven(t)) q.push(q.front());
        q.pop();
        t++;
    }
    cout << q.front();
    return 0;
}