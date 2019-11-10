#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[100], b[100], ans[10000] = {0};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() < s2.length()) swap(s1, s2);
    int lena = s1.length(), lenb = s2.length();
    //Save to array
    for (int i = 0; i < lena; ++i) {
        a[i] = s1[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; ++i) {
        b[i] = s2[lenb - i - 1] - '0';
    }
    // Calculate
    for (int i = 0; i < lenb; ++i) {
        for(int j = 0; j < lena; ++j) {
            ans[i + j] += b[i] * a[j];
            if (ans[i + j] >= 10) {
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }
        }
    }
    //Output the result
    bool flag = false;
    for (int i = lena * lenb + 1; i >= 0; --i) {
        if (ans[i] != 0) flag = true;
        if (ans[i] == 0 && !flag) continue;
        cout << ans[i];
    }
    return 0;
}