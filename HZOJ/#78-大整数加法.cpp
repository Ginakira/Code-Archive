#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a[110], b[110], ans[110];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == "0" && s2 == "0") {
        cout << "0" << endl;
        return 0;
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(ans, 0, sizeof(ans));
    for (int i = s1.length() - 1, j = 0; i >= 0; --i) {
        a[j++] = s1[i] - '0';
    }
    for (int i = s2.length() - 1, j = 0; i >= 0; --i) {
        b[j++] = s2[i] - '0';
    }
    int maxlen = s1.length() > s2.length() ? s1.length() : s2.length();
    for (int i = 0; i < maxlen; ++i) {
        ans[i] += a[i] + b[i];
        if(ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    bool flag = false;
    for(int i = maxlen; i >= 0; --i) {
        if(ans[i] != 0) flag = true;
        if (ans[i] == 0 && !flag) continue;
        cout << ans[i];
    }
    return 0;
}