#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int m, n;
int stu[130], maxstu[15] = {0};

bool cmp(int a, int b) { return a > b; }

int main() {
    int k = 0;
    double ans = 0;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> stu[k];
            ans += stu[k];
            maxstu[j] = max(maxstu[j], stu[k]);
            k++;
        }
    }
    sort(stu, stu + m * n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << maxstu[i] << endl;
    }
    ans /= m * n;
    int ans2 = (ans * 10 + 5) / 10;
    int cnt = 0;
    for (int i = 0; i < m * n; ++i) {
        if (i != 0) cout << ' ';
        cout << stu[i];
        if (stu[i] >= ans2) cnt++;
    }
    printf("\n%d\n%d", ans2, cnt);
    return 0;
}