#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[1000], b[1000];

int main() {
    string s1, s2;
    bool reg = false;
    cin >> s1 >> s2;
    if(s1 < s2) {
        swap(s1, s2);
        reg = true;
    }
    int lena = s1.length(), lenb = s2.length();
    //Save to array
    for (int i = 0; i < lena; ++i) {
        a[i] = s1[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; ++i) {
        b[i] = s2[lenb - i - 1] - '0';
    }
    //Calculate
    for (int i = 0; i < lena; ++i) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        a[i] -= b[i];
    }
    //Output the result
    bool flag = false;
    if (reg) cout << '-';
    for (int i = lena + 1; i >= 0; --i) {
        if (a[i] != 0) flag = true;
        if (a[i] == 0 && !flag) continue;
        cout << a[i];
    }
    return 0;
}