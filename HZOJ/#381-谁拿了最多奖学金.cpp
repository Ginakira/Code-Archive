/************************************************************
    File Name : #381-谁拿了最多奖学金.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 18:41:37
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name;
    int id, ave, cls, pap, total;
    char cad, wst;
};

bool cmp(Stu a, Stu b) {
    if (a.total == b.total) return a.id < b.id;
    return a.total > b.total;
}

Stu stu[110];

int cal(Stu &a) {
    if (a.ave > 80 && a.pap >= 1) a.total += 8000;
    if (a.ave > 85 && a.cls > 80) a.total += 4000;
    if (a.ave > 90) a.total += 2000;
    if (a.wst == 'Y' && a.ave > 85) a.total += 1000;
    if (a.cad == 'Y' && a.cls > 80) a.total += 850;
    return a.total;
}

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stu[i].id = i;
        cin >> stu[i].name >> stu[i].ave >> stu[i].cls >> stu[i].cad >>
            stu[i].wst >> stu[i].pap;
        sum += cal(stu[i]);
    }
    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].total << endl << sum << endl;
    return 0;
}