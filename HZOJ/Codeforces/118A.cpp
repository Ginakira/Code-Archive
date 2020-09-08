/************************************************************
    File Name : 118A.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/08 09:06:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto is_vowel = [](char c) {
    switch (c) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
        case 'Y':
        case 'y':
            return true;
    };
    return false;
};

int main() {
    string s, ans;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (is_vowel(s[i])) continue;
        ans += '.';
        ans += (s[i] < 'a' ? s[i] + 32 : s[i]);
    }
    cout << ans << endl;
    return 0;
}