/************************************************************
    File Name : 65A.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/07 23:08:42
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int len = s.size();
        if (len <= 10) {
            cout << s << endl;
            continue;
        }
        cout << s[0] << len - 2 << s[len - 1] << endl;
    }
    return 0;
}