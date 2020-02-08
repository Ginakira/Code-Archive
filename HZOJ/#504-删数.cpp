/************************************************************
    File Name : #504-删数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/08 21:22:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> s >> n;
    int len = s.length();
    int index = 0;
    while (n) {
        index = 0;
        while (s[index] <= s[index + 1]) ++index;
        s.erase(index, 1);
        len--, n--;
    }
    bool flag = false;
    for (int i = 0; i < len; ++i) {
        if (!flag && s[i] == '0') continue;
        flag = true;
        cout << s[i];
    }
    return 0;
}