#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name, sex;
    int y, m;
};

Stu stu[110];

bool cmp(Stu a, Stu b) {
    if (a.y == b.y) {
        return a.m > b.m;
    }
    return a.y > b.y;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name >> stu[i].sex >> stu[i].y >> stu[i].m;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << stu[i].name << ' ' << stu[i].sex << ' ' << stu[i].y << ' '
             << stu[i].m << endl;
    }
    return 0;
}