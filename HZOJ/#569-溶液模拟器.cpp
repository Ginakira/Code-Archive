/************************************************************
    File Name : #569-溶液模拟器.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/20 20:38:35
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<pair<int, int>> s;

int main() {
    int sv, sc, v, c, n;
    double mass, total;
    cin >> sv >> sc >> n;
    mass = sv * sc;
    total = sv;
    char op;
    for (int i = 0; i < n; ++i) {
        cin >> op;
        if (op == 'P') {
            cin >> v >> c;
            pair<int, int> liq(v, c);
            s.push(liq);
            mass += v * c;
            total += v;
        } else {
            if (!s.empty()) {
                mass -= s.top().first * s.top().second;
                total -= s.top().first;
                s.pop();
            }
        }
        printf("%.0f %.5f\n", total, mass / total);
    }
    return 0;
}