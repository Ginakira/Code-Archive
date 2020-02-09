/************************************************************
    File Name : #519-优雅数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-12-05 17:45:34
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int mark[10];

bool is_elegent_number(int a) {
    memset(mark, 0, sizeof(mark));
    string s = to_string(a);
    while (a > 0) {
        mark[a % 10]++;
        a /= 10;
    }
    int cnt = 0, tmp = 0;
    char num;
    for (int i = 0; i < 10; ++i) {
        if (mark[i] == 0) cnt++;
        if (mark[i] == 1) num = i + '0';
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == num) tmp++;
    }
    return cnt == 8 && tmp == 1;
}

int main() {
    long long l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (is_elegent_number(i)) cnt++;
    }
    cout << cnt;
    return 0;
}