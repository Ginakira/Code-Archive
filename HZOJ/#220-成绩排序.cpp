#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name;
    int c, m, e, g, total;
};

Stu stu[110];

void out() {
    for (int i = 0; i < 4; ++i) {
        if (i != 0) cout << ' ';
        cout << stu[i].name;
    }
    cout << endl;
    return;
}

bool cmp1(Stu a, Stu b) {
    if (a.c == b.c)
        return a.name < b.name;
    else
        return a.c > b.c;
}

bool cmp2(Stu a, Stu b) {
    if (a.m == b.m)
        return a.name < b.name;
    else
        return a.m > b.m;
}

bool cmp3(Stu a, Stu b) {
    if (a.e == b.e)
        return a.name < b.name;
    else
        return a.e > b.e;
}

bool cmp4(Stu a, Stu b) {
    if (a.g == b.g)
        return a.name < b.name;
    else
        return a.g > b.g;
}

bool cmp5(Stu a, Stu b) {
    if (a.total == b.total)
        return a.name < b.name;
    else
        return a.total > b.total;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name >> stu[i].c >> stu[i].m >> stu[i].e >> stu[i].g;
        stu[i].total = stu[i].c + stu[i].m + stu[i].e + stu[i].g;
    }
    sort(stu, stu + n, cmp1);
    out();
    sort(stu, stu + n, cmp2);
    out();
    sort(stu, stu + n, cmp3);
    out();
    sort(stu, stu + n, cmp4);
    out();
    sort(stu, stu + n, cmp5);
    out();
    return 0;
}