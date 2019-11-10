#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
            if (sum > m) {
                ans++;
                sum = a;
            }
        }
        if (sum > 0) ans++;
        cout << ans << '\n';
    }
    return 0;
}