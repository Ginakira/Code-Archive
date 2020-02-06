/************************************************************
    File Name : #479-乒乓球.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/05 20:40:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void statistic(string s, int point) {
    int win = 0, lose = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'W')
            win++;
        else
            lose++;
        if ((win >= point || lose >= point) && abs(win - lose) >= 2) {
            cout << win << ":" << lose << endl;
            win = 0, lose = 0;
        }
    }
    cout << win << ":" << lose << endl;
    return;
}

int main() {
    string s = "", tmp;
    while (cin >> tmp) {
        s += tmp;
    }
    s = s.substr(0, s.find('E'));
    statistic(s, 11);
    cout << endl;
    statistic(s, 21);
    return 0;
}