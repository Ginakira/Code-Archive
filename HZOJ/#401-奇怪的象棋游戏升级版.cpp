/************************************************************
    File Name : #401-奇怪的象棋游戏升级版.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/01 20:57:07
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct node {
    int x, y, step;
};

int ans[505][505];
int dir[12][2] = {{1, 2},   {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                  {-1, -2}, {1, -2}, {2, 2}, {-2, 2}, {2, -2}, {-2, -2}};

void solve() {
    queue<node> q;
    node temp;
    q.push({1, 1, 1});
    ans[1][1] = 1;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 12; ++i) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x < 1 || y < 1 || x > 500 || y > 500 || ans[x][y]) continue;
            ans[x][y] = temp.step + 1;
            q.push({x, y, temp.step + 1});
        }
    }
    return;
}

int main() {
    solve();
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        cout << ans[x][y] - 1 << endl;
    }
    return 0;
}