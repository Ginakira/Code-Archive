/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/30 16:27:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000

struct Node {
    int x, y, c;
};

struct UnionSet {
    int *fa, *val;
    UnionSet(int n) {
        fa = new int[n + 5];
        val = new int[n + 5];
        for (int i = 0; i <= n; ++i) {
            fa[i] = i, val[i] = 0;
        }
        return;
    }

    int get(int x) {
        if (x == fa[x]) return x;
        int xx = get(fa[x]);
        val[x] += val[xx];
        val[x] %= 2;
        return fa[x] = xx;
    }

    int merge(int a, int b, int t) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return (val[a] - val[b] - t) % 2 == 0;
        fa[aa] = bb;
        val[aa] = (t + val[b] - val[a] + 2) % 2;
        return 1;
    }
};

Node arr[MAX_N + 5];

bool cmp(Node &a, Node &b) { return a.c > b.c; }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].x >> arr[i].y >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    UnionSet u(n);
    for (int i = 0; i < m; ++i) {
        if (u.merge(arr[i].x, arr[i].y, 1)) continue;
        cout << arr[i].c << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}