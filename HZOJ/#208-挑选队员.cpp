#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int stu[110];

bool cmp(int a, int b) { return a > b; }

int main() {
    int m, n;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> stu[i];
    }
    cin >> n;
    sort(stu, stu + m, cmp);
    int ans = 1, pre = stu[0];
    for (int i = 1; i < m; ++i) {
        if (stu[i] == pre) {
            ans++;
            if (ans >= n && stu[i + 1] != stu[i]) break;
        } else {
            ans = 1, pre = stu[i];
        }
    }
    cout << ans << endl;
    /* for (int i = 0; i < m; ++i) {
        cout << stu[i] << endl;
    } */
    return 0;
}