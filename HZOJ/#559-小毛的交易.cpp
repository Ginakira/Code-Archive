/************************************************************
    File Name : #559-小毛的交易.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/29 18:28:12
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Data {
    int bean, food;
    double performance;
} house[1005];

bool cmp(const Data &a, const Data &b) { return a.performance > b.performance; }

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> house[i].bean >> house[i].food;
        house[i].performance = house[i].bean * 1.0 / house[i].food;
    }
    sort(house, house + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (house[i].food <= m) {
            ans += house[i].bean;
            m -= house[i].food;
        } else {
            ans += house[i].performance * m;
            break;
        }
    }
    printf("%.3f\n", ans);

    return 0;
}