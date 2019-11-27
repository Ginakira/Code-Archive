/************************************************************
    File Name : #582-字符串乘方.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 21:03:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int find_sub(string s, string sub) {
    int num = 0;
    size_t len = sub.length();
    if(len == 0) len = 1;
    for(size_t i = 0; (i = s.find(sub, i)) != s.npos; ++num, i += len);
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        int ans = 1;
        if (s == ".") break;
        int len = s.length();
        for (int i = 1; i <= len / 2; ++i) {
            int tmp = find_sub(s, s.substr(0, i));
            if(tmp * i == len) ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}