/************************************************************
    File Name : #326-食物链.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/23 20:41:23
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500000
int fa[MAX_N + 5], val[MAX_N + 5];  // i to father weight

// 带权并查集
// 0 同类 1 前者吃后者

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        val[i] = 0;
    }
    return;
}

int get(int x) {  // get root of x
    if (x == fa[x]) return x;
    int root = get(fa[x]);
    val[x] += val[fa[x]];
    val[x] %= 3;
    return fa[x] = root;
}

int merge(int x, int y, int t) {  // t: realtions of x and y
    int a = get(x), b = get(y);
    if (a == b) {
        return (val[x] - val[y] - t) % 3 == 0;
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 3) % 3;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, ans = 0;
    cin >> n >> k;
    init(n);
    for (int i = 0; i < k; ++i) {
        int x, y, t;
        cin >> t >> x >> y;
        t--;
        /*if (t == 1) t == 0;
        else t == 1;*/
        if (x <= n && y <= n && merge(x, y, t)) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}