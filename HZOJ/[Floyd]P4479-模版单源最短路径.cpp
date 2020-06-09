/************************************************************
    File Name : [Floyd]P4479-模版单源最短路径.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/06/09 23:11:24
************************************************************/

#include <cstring>
#include <iostream>
using namespace std;

int n, m, s, ans[1005][1005];

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        ans[a][b] = c;
    }
    for (int i = 1; i <= n; ++i) {
        ans[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        i == 1 || cout << ' ';
        cout << ans[s][i];
    }
    cout << endl;
    return 0;
}