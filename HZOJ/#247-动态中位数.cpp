/************************************************************
    File Name : #247-动态中位数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/25 21:14:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 9999
typedef pair<int, int> PII;
set<PII> small, large;

int arr[MAX_N + 5], stamp;

void add_num(int x) {
    if (small.empty() || x <= -(small.begin()->first)) {
        small.insert({-x, stamp++});
    } else {
        large.insert({x, stamp++});
    }
    if (small.size() + 2 == large.size()) {
        PII temp = *large.begin();
        temp.first = -(temp.first);
        small.insert(temp);
        large.erase(large.begin());
    } else if (large.size() + 2 == small.size()) {
        PII temp = *small.begin();
        temp.first = -(temp.first);
        large.insert(temp);
        small.erase(small.begin());
    }
    return;
}

void output(int ind) {
    if (small.size() > large.size()) {
        cout << -(small.begin()->first);
    } else {
        cout << large.begin()->first;
    }
    cout << ' ';
    if (ind % 10 == 0) cout << endl;
    return;
}

void solve() {
    small.clear();
    large.clear();
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; ++i) {
        cin >> arr[i];
    }
    cout << a << ' ' << (b + 1) / 2 << endl;
    int ind = 1;
    for (int i = 1; i <= b; ++i) {
        add_num(arr[i]);
        if (i & 1) output(ind++);
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    while (N--) solve();
    return 0;
}