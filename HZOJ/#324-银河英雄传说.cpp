/************************************************************
    File Name : #324-银河英雄传说.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/28 11:18:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5], size[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            val[i] = 0;
            size[i] = 1;
        }
        return;
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        return fa[x] = root;
    }
    void merge(int a, int b) {  // a接到b上
        int aa = get(a), bb = get(b);
        if (aa == bb) return;
        fa[aa] = bb;
        val[aa] = size[bb];
        size[bb] += size[aa];
        return;
    }
};

UnionSet u;

int main() {
    int n;
    scanf("%d", &n);
    u.init(n);
    char str[10];
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%s%d%d", str, &a, &b);
        switch (str[0]) {
            case 'M': {
                u.merge(a, b);
            } break;
            case 'C': {
                if (u.get(a) != u.get(b)) {
                    printf("-1\n");
                } else {
                    printf("%d\n", abs(u.val[a] - u.val[b]) - 1);
                }
            } break;
        }
    }
    return 0;
}