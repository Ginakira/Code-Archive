/************************************************************
    File Name : #387-吃瓜群众升级版.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/08 20:03:50
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

struct Node {
    int id, amount;
};

bool cmp(Node a, Node b) { return a.amount < b.amount; }

Node melon[MAX_N + 5];
int n, m;

int binary_search(int target) {
    int l = 0, r = m - 1;
    while (l != r) {
        int mid = (l + r) >> 1;
        if (melon[mid].amount >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return melon[l].id;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> melon[i].amount;
        melon[i].id = i + 1;
    }
    sort(melon, melon + m, cmp);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        if (temp > melon[m - 1].amount) {
            cout << 0 << endl;
            continue;
        }
        cout << binary_search(temp) << endl;
    }
    return 0;
}