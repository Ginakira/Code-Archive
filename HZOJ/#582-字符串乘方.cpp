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

int main() {
    int ans = 1;
    string s;
    while (cin >> s) {
        if (s == ".") break;
        int len = s.length();
        for (int i = 1; i < len / 2; ++i) {
            int tmp = 0;
            string sub = s.substr(0, i);
            for (int j = 0; j < len; j += i) {
                string sub2 = s.substr(0, i);
                if (sub == sub2)
                    tmp++;
                else {
                    tmp = 0;
                    break;
                }
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}