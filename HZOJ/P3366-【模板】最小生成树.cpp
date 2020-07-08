/************************************************************
    File Name : P3366-【模板】最小生成树(Kruskal).cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/08 18:18:41
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 200000

struct Edge {
    int from, to, val;
};

bool cmp(Edge a, Edge b) { return a.val < b.val; }

Edge edge[MAX_N + 5];
int n, m, ans, my_union[5005], already = 1;

int find_root(int x) {
    return my_union[x] = (my_union[x] == x ? x : find_root(my_union[x]));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    }

    // 并查集初始化
    for (int i = 1; i <= n; ++i) {
        my_union[i] = i;
    }

    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; ++i) {
        int ra = find_root(edge[i].from), rb = find_root(edge[i].to);
        if (ra == rb) continue;
        ans += edge[i].val;
        my_union[ra] = rb;
        already++;
        if (already == n) break;
    }

    if (already == n) {
        cout << ans;
    } else {
        cout << "orz";
    }

    return 0;
}