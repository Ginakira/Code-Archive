/************************************************************
    File Name : #72-练习题2：猜拳.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/27 19:52:09
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            val[i] = 0;  // 平手
        }
    }

    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }

    void merge(int a, int b, int c) {  // c 0平手 1 a输b 2 a赢b
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 3) % 3;
        return;
    }
};

UnionSet u;

void read(int &n, int &m) {
    cin >> n >> m;
    return;
}

int main() {
    int n, m;
    read(n, m);
    u.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown\n";
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0:
                        cout << "Tie\n";
                        break;
                    case 1:
                        cout << "Loss\n";
                        break;
                    case 2:
                        cout << "Win\n";
                        break;
                }
            }
        }
    }
    return 0;
}