#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Stu {
    int num, height;
};

Stu stu[1010];

bool cmp(Stu a, Stu b) {
    if (a.height == b.height) return a.num < b.num;
    else
        return a.height < b.height;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> stu[i].height;
        stu[i].num = i + 1;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << stu[i].num;
    }
    return 0;
}