/************************************************************
    File Name : #564-起床困难综合症.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/02/05 18:22:40
************************************************************/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

bitset<30> zero, one, ans;

int main() {
    one.set();
    int n, m, t;
    string op;
    cin >> n >> m;
    while (n--) {
        cin >> op >> t;
        if (op == "AND")
            zero &= t, one &= t;
        else if (op == "OR")
            zero |= t, one |= t;
        else
            zero ^= t, one ^= t;
    }
    for (int i = 0; i < 30; ++i) {
        if (zero[i] | (one[i] && ans.to_ulong() < m)) ans[i] = 1;
    }
    cout << ans.to_ulong() << endl;
    return 0;
}