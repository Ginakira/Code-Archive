/************************************************************
    File Name : #507-大神排队.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-24 19:14:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int influ, hold;
};

Student stu[50010];

bool cmp(Student a, Student b) {
    if (a.hold == b.hold)
        return a.influ < b.influ;
    else
        return a.hold < b.hold;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].influ >> stu[i].hold;
    }
    sort(stu, stu + n, cmp);
    int sum = 0, max_hurt = -999999999;
    for (int i = 0; i < n; ++i) {
        max_hurt = max(max_hurt, sum - stu[i].hold);
        sum += stu[i].influ;
    }
    cout << max_hurt;
    return 0;
}