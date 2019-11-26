/************************************************************
    File Name : #581-字符串匹配.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-26 18:28:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    string a, b;
    while (cin >> a) {
        if (a == "-1") break;
        cin >> b;
        int lena = a.length(), lenb = b.length();
        int max_match = 0, total_len = lena + lenb;
        for (int i = 0; i < lena; ++i) {
            int cnt = 0;
            for (int j = 0, k = i; j < lenb && k < lena; ++j, ++k) {
                if (a[k] == b[j]) cnt++;
            }
            max_match = max(cnt, max_match);
        }
        for (int i = 0; i < lenb; ++i) {
            int cnt = 0;
            for (int j = 0, k = i; j < lena && k < lenb; ++j, ++k) {
                if (a[j] == b[k]) cnt++;
            }
            max_match = max(cnt, max_match);
        }
        max_match *= 2;
        cout << "appx(" << a << "," << b << ") = ";
        if (max_match % total_len == 0) {
            cout << max_match / total_len << "\n";
        } else {
            int tmp = gcd(max_match, total_len);
            cout << max_match / tmp << '/' << total_len / tmp << "\n";
        }
    }
    return 0;
}