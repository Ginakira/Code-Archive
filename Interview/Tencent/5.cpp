#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] % m == 0) {
            cout << 1 << endl;
            return;
        }
    }
    for (int len = 2; len <= n; ++len) {
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}