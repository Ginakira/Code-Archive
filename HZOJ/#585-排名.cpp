/************************************************************
    File Name : #585-排名.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-24 18:31:57
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int score, grade, ans;
};

Student stu[555];

bool cmp(Student a, Student b) {
    if (a.score == b.score)
        return a.grade < b.grade;
    else
        return a.score > b.score;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].score >> stu[i].grade;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (stu[j].grade < stu[i].grade) ++cnt;
        }
        stu[i].ans = cnt;
    }
    for (int i = 0; i < n; ++i) {
        cout << stu[i].ans << endl;
    }
    return 0;
}