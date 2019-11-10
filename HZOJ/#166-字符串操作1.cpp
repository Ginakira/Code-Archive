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
    if (l > 100)
        cout << 100 << endl;
    else
        cout << l << endl;
    ans = a.substr(0, n - 1) + b + a.substr(n - 1, l - n + 1);
    cout << ans << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 1; i <= l + l1; ++i) {
        if (ans[i - 1] == 'x') {
            cout << i << endl;
            break;
        }
    }
    return 0;
}