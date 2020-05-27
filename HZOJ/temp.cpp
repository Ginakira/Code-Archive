/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/27 22:26:18
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500000
int a[MAX_N + 5], b[MAX_N + 5];
int qa[MAX_N + 5], qb[MAX_N + 5];
int top1 = -1, top2 = -1;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int p = 1;
    while (p <= n) {
        while (top1 != -1 && a[qa[top1]] >= a[p]) top1--;
        while (top2 != -1 && b[qb[top2]] >= b[p]) top2--;
        if (top1 != top2) break;
        qa[++top1] = p, qb[++top2] = p;
        p++;
    }
    cout << p - 1 << endl;
    return 0;
}