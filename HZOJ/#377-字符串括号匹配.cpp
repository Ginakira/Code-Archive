/************************************************************
    File Name : #377-字符串括号匹配.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/10 00:09:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> bracket;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') bracket.push(s[i]);
        if (s[i] == ')') {
            if (!bracket.empty())
                bracket.pop();
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (bracket.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}