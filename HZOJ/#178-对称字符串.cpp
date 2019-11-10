#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string ans[23] = {"A"};

int main() {
    int n;
    string a = "A";
    cin >> n;
    for (int i = 1; i < n; ++i) {
        string tmp = ans[i - 1];
        reverse(tmp.begin(), tmp.end());
        a[0]++;
        ans[i] = ans[i - 1] + a + tmp;
    }
    cout << ans[n - 1];
    return 0;
}