/************************************************************
    File Name : #484-柱状统计图.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 11:35:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int mark[2333] = {0};

int main() { 
    string s;
    int maxh = 0;
    while (cin >> s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                mark[s[i] - 'A']++;
                maxh = max(maxh, mark[s[i] - 'A']);
            }
        }
    }
    for (int i = maxh; i > 0; --i) {
        int last = 0;
        for (int j = 0; j < 26; ++j) {
            if (mark[j] >= i)
                last = j;
        }
        for(int j = 0; j <= last; ++j) {
            if(j > 0) cout << ' ';
            if(mark[j] >= i) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 26; ++i) {
        if (i > 0) cout << ' ';
        cout << char('A' + i);
    }

    return 0;
}