/************************************************************
    File Name : #284-超市卖货.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/28 11:13:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000

struct Node {
    int profit, expire;

    bool operator<(const Node &a) const { return profit < a.profit; }
};

priority_queue<Node> q;
bool mark[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int profit, expire;
        cin >> profit >> expire;
        q.push({profit, expire});
    }
    int ans = 0;
    while (!q.empty()) {
        Node temp = q.top();
        q.pop();
        for (int i = temp.expire; i > 0; --i) {
            if (!mark[i]) {
                ans += temp.profit;
                mark[i] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}