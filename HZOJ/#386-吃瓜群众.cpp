/************************************************************
    File Name : #386-吃瓜群众.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 20:14:44
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, int> melon;

int main() {
    int m, n, tmp;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> tmp;
        melon[tmp] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        cout << melon[tmp] << endl;
    }
    return 0;
}