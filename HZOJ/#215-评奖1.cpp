#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    string name;
    int math, chn, eng, geo;
    int total;
};

bool cmp(Stu a, Stu b) { return a.total > b.total; }

Stu stu[43];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name;
        cin >> stu[i].math >> stu[i].chn >> stu[i].eng >> stu[i].geo;
        stu[i].total = stu[i].math + stu[i].chn + stu[i].eng + stu[i].geo;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 3; ++i) {
        cout << stu[i].name << endl;
    }
    return 0;
}