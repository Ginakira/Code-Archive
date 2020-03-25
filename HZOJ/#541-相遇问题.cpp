/************************************************************
    File Name : #541-相遇问题.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/03/25 19:07:33
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, atime[2][20][20], ans[2][100000], ans_num[2];

void func(int people, int location, int cost) {
    if (location == n) {
        ans[people][ans_num[people]++] = cost;
        return;
    }
    for (int i = location + 1; i <= n; ++i) {
        if (atime[people][location][i]) {
            func(people, i, cost + atime[people][location][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b, c, d;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c >> d;
        atime[0][a][b] = atime[0][b][a] = c;
        atime[1][a][b] = atime[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    sort(ans[0], ans[0] + ans_num[0]);
    sort(ans[1], ans[1] + ans_num[1]);
    for (int i = 0; i < ans_num[0]; ++i) {
        for (int j = 0; j < ans_num[1]; ++j) {
            if (ans[0][i] == ans[1][j]) {
                cout << ans[0][i] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}