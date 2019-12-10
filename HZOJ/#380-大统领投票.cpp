/************************************************************
    File Name : #380-大统领投票.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/10 00:33:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

pair<int, string> ticket[110];

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.second.length() == b.second.length()) {
        int len = a.second.length();
        for (int i = 0; i < len; ++i) {
            if (a.second[i] > b.second[i]) return true;
        }
        return false;
    }
    return a.second.length() > b.second.length();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ticket[i].second;
        ticket[i].first = i + 1;
    }
    sort(ticket, ticket + n, cmp);
    cout << ticket[0].first << endl << ticket[0].second << endl;
    return 0;
}