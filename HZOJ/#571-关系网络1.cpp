/************************************************************
    File Name : #571-关系网络1.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 10:04:32
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100
int arr[MAX_N + 5][MAX_N + 5];
bool vis[MAX_N + 5];

struct Node {
    int id, step;
};

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }
    queue<Node> q;
    q.push({x, 0});
    vis[x] = 1;
    while (!q.empty()) {
        Node temp = q.front();
        q.pop();
        if (temp.id == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && arr[temp.id][i]) {
                q.push({i, temp.step + 1});
                vis[i] = 1;
            }
        }
    }
    return 0;
}