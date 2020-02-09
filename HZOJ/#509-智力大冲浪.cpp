/************************************************************
    File Name : #509-智力大冲浪.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/09 18:44:29
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 505
pair<int, int> task[MAXN];
bool mark[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main() {
    fill(mark, mark + MAXN, false);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> task[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> task[i].second;
    }
    sort(task, task + n, cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = task[i].first; j > 0; --j) {
            if (!mark[j]) {
                mark[j] = true;
                task[i].second = 0;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        m -= task[i].second;
    }
    cout << m << endl;
    return 0;
}