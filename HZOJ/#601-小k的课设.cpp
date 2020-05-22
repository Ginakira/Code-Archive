/************************************************************
    File Name : #601-小k的课设.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/22 21:41:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

map<int, set<int>> stu, lesson;

void solve() {
    stu.clear();
    lesson.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        stu[a].insert(b);
        lesson[b].insert(a);
    }
    for (auto &it : stu) {
        cout << "S " << it.first;
        for (int val : it.second) {
            cout << " " << val;
        }
        cout << endl;
    }
    for (auto &it : lesson) {
        cout << "L " << it.first;
        for (int val : it.second) {
            cout << " " << val;
        }
        cout << endl;
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}