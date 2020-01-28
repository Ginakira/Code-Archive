/************************************************************
    File Name : #477-元音字母.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/28 15:17:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    string s;
    cin >> s;
    int pre = s.length(), ans = 1;
    for (int i = 0; i < s.length(); ++i) {
        if (is_vowel(s[i])) {
            ans = max(ans, i - pre);
            pre = i;
        }
    }
    cout << ans << endl;
    return 0;
}