/************************************************************
    File Name : #71-[竞赛版]练习题1：朋友圈.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/27 17:02:46
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; ++i) fa[i] = i;
        return;
    }

    int get(int x) { return (fa[x] = (x - fa[x] ? get(fa[x]) : x)); }

    void merge(int a, int b) {
        fa[get(a)] = get(b);
        return;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1:
                u.merge(b, c);
                break;
            case 2:
                cout << (u.get(b) - u.get(c) ? "No" : "Yes") << endl;
                break;
        }
    }
    return 0;
}