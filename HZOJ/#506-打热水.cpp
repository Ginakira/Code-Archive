/************************************************************
    File Name : #506-打热水.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/13 18:09:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 2000
pair<int, int> stu[MAX_N + 5];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &stu[i].second);
        stu[i].first = i;
    }
    sort(stu + 1, stu + n + 1, cmp);
    double ans = 0;
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        i == 1 || printf(" ");
        now += stu[i - 1].second;
        ans += now;
        printf("%d", stu[i].first);
    }
    printf("\n%.2f\n", ans / n);
    return 0;
}