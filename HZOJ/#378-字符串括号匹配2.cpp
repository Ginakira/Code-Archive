/************************************************************
    File Name : #378-字符串括号匹配2.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/10 00:20:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

stack<char> bracket;
map<char, char> mp;
int main() {
    mp[')'] = '(';
    mp['}'] = '{';
    mp[']'] = '[';
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') bracket.push(s[i]);
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (!bracket.empty()) {
                if (bracket.top() == mp[s[i]]) bracket.pop();
            } else {
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