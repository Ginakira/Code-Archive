/************************************************************
    File Name : #538-图的遍历.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/03/25 18:14:01
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, num[25][25], check[25];
bool flag = false;

void func(int x) {
    if (flag) {
        cout << '-';
    }
    flag = true;
    cout << x;
    for (int i = 1; i <= n; ++i) {
        if (num[x][i] == 1 && check[i] == 0) {
            check[i] = 1;
            func(i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> num[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (check[i] == 0) {
            check[i] = 1;
            func(i);
        }
    }
    return 0;
}