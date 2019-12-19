/************************************************************
    File Name : #388-奇怪的刮刮乐.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/18 20:22:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#define LL long long
using namespace std;

map<LL, bool> md, nd;
LL mnum[100010];

int main() {
    int m, n, tmp;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> mnum[i];
        md[mnum[i]] = true;
    }
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nd[tmp] = true;
    }
    LL sum = 0;
    for (int i = 0; i < m; ++i) {
        if (md[mnum[i]] && nd[mnum[i]]) {
            cout << (sum > 0 ? " " : "") << mnum[i];
            sum += mnum[i];
        }
    }
    cout << endl << sum << endl;
    return 0;
}