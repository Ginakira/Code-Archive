/************************************************************
    File Name : 前中序求后序.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/26 15:19:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string q, z;

void func(int qs, int qe, int zs, int ze) {
    if (qe < qs) {
        return;
    }
    if (qs == qe) {
        cout << q[qs];
        return;
    }

    char root = q[qs];
    for (int i = zs; i <= ze; ++i) {
        if (z[i] == root) {
            func(qs + 1, (i - zs) + qs, zs, i - 1);
            func(i - zs + qs + 1, qe, i + 1, ze);
            cout << root;
            break;
        }
    }
}

int main() {
    while (cin >> q >> z) {
        func(0, q.size() - 1, 0, z.size() - 1);
        cout << endl;
    }
    return 0;
}