/************************************************************
    File Name : #504-删数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/13 18:43:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    for (int i = 0; i < n; ++i) {
        int ind = str.size() - 1;
        for (int j = 0; j < str.size() - 1; j++) {
            if (str[j] > str[j + 1]) {
                ind = j;
                break;
            }
        }
        str.replace(ind, 1, "");
    }
    int flag = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != '0') flag = 1;
        if (flag) cout << str[i];
    }
    cout << endl;
    return 0;
}