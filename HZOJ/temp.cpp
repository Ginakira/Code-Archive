/************************************************************
    File Name : 树状数组-P3374.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/04/19 09:09:52
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 500000

inline int lowbit(int x) { return x & (-x); }

int arr[MAX_N + 5];
int C[MAX_N + 5];

void update(int ind, int val, int n) {
    while (ind <= n) {
        C[ind] += val;
        ind += lowbit(ind);
    }
    return;
}

int query(int ind) {
    int sum = 0;
    while (ind) {
        sum += C[ind];
        ind -= lowbit(ind);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i], n);
    }

    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c, n);
        } else {
            cout << query(c) - query(b - 1) << endl;
        }
    }

    return 0;
}