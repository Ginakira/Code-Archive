/************************************************************
    File Name : #375-奖学金.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/11 18:51:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id, chn, math, eng, total;
};

Student student[333];

bool cmp(Student a, Student b) {
    if (a.total == b.total) {
        if (a.chn == b.chn) {
            return a.id < b.id;
        }
        return a.chn > b.chn;
    }
    return a.total > b.total;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> student[i].chn >> student[i].math >> student[i].eng;
        student[i].id = i + 1;
        student[i].total = student[i].chn + student[i].math + student[i].eng;
    }
    sort(student, student + n, cmp);
    for (int i = 0; i < 5; ++i) {
        cout << student[i].id << ' ' << student[i].total << endl;
    }
    return 0;
}