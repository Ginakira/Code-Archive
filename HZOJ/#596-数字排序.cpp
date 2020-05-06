/************************************************************
    File Name : #596-数字排序.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/05/06 16:10:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 5000
string a[MAX_N + 5];

bool cmp(const string &a, const string &b) {
    int lena = a.size(), lenb = b.size();
    if (lena != lenb) return lena < lenb;
    for (int i = 0; i < lena; ++i) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i) cout << a[i] << endl;
    return 0;
}