#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, ans;
    int n, l, l1;
    cin >> a >> n >> b;
    l = a.length(), l1 = b.length();
    cout << l << endl;
    for (int i = 1; i <= l; ++i) {
        if (a[i - 1] == 'a') {
            cout << i << endl;
            break;
        }
    }
    ans = a.substr(0, n - 1) + b + a.substr(n - 1, l - n + 1);
    cout << ans << endl;
    return 0;
}