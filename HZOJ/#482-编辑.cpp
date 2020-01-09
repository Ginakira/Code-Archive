/************************************************************
    File Name : #482-编辑.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/09 18:55:07
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string article, c;
    cin >> article;
    int cnt, cur = article.length();
    char op;
    cin >> cnt;
    while (cnt--) {
        cin >> op;
        switch (op) {
            case 'L': {
                if (cur > 0) cur--;
            } break;
            case 'D': {
                if (cur < article.length()) cur++;
            } break;
            case 'B': {
                if (cur == 0) break;
                article.erase(--cur, 1);
            } break;
            case 'P': {
                cin >> c;
                article.insert(cur, c);
                cur++;
            } break;
            default:
                break;
        }
    }
    cout << article << endl;
    return 0;
}