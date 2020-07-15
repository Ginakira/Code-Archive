/************************************************************
    File Name : P1340-兽径管理.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/15 18:54:07
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Edge {
    int from, to, val, mtime;
};

bool cmp(Edge &a, Edge &b) { return a.val < b.val; }

Edge edg[6005];
int n, m, my_union[205];

int find_fa(int x) {
    if (my_union[x] != x) {
        return my_union[x] = find_fa(my_union[x]);
    }
    return x;
}

void init_union() {
    for (int i = 1; i <= n; ++i) {
        my_union[i] = i;
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
        edg[i].mtime = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i < m; ++i) {
        int ans = 0, already = 1;
        init_union();
        for (int j = 0; j < m; ++j) {
                }
    }
    return 0;
}