/************************************************************
    File Name : #287-合并果子[way2].cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/23 18:55:14
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, a, t = 0, sum = 0;
    cin >> n;
    set<PII> s;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    for (int i = 0; i < n - 1; ++i) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a + b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}