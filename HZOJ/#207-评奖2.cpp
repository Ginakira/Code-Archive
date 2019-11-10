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

Stu stu[33];

int main() {
    int n, maxs = -1, mins = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].name;
        cin >> stu[i].math >> stu[i].chn >> stu[i].eng >> stu[i].geo;
        stu[i].total = stu[i].math + stu[i].chn + stu[i].eng + stu[i].geo;
        maxs = max(maxs, stu[i].math), mins = min(mins, stu[i].math);
        maxs = max(maxs, stu[i].chn), mins = min(mins, stu[i].chn);
        maxs = max(maxs, stu[i].eng), mins = min(mins, stu[i].eng);
        maxs = max(maxs, stu[i].geo), mins = min(mins, stu[i].geo);
    }
    int high = 0;
    string higher = "";
    for (int i = 0; i < n; ++i) {
        cout << stu[i].total << endl;
        if(stu[i].total > high) {
            high = stu[i].total;
            higher = stu[i].name;
        }
    }
    cout << higher << endl << maxs << ' ' << mins << endl;
    return 0;
}