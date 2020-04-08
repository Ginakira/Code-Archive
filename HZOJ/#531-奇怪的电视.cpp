/************************************************************
    File Name : #531-奇怪的电视.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 19:05:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int status, step;
};

int n, num[25], arr[25][25];
bool visited[2100000];

void init() {
    int t = 1;
    for (int i = 0; i < 21; ++i) {
        num[i] = t;
        t *= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    cin >> n;
    int start_status = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t & 1) start_status += num[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i][0];
        for (int j = 1; j <= arr[i][0]; ++j) {
            cin >> arr[i][j];
            arr[i][24] += num[arr[i][j]];
        }
    }
    queue<Node> que;
    que.push({start_status, 0});
    visited[start_status] = 1;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        if (temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (!(temp.status & num[i])) {
                int status_temp = temp.status + num[i];
                status_temp &= ~(arr[i][24]);
                if (!visited[status_temp]) {
                    visited[status_temp] = 1;
                    que.push({status_temp, temp.step + 1});
                }
            }
        }
    }
    return 0;
}