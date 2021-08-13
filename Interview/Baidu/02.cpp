#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> score(n, 0);
    for (int i = 0; i < m; ++i) {
        vector<int> mark(n, 0);
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int l, r;
            cin >> l >> r;
            for (int t = l; t <= r; ++t) {
                if (mark[t - 1]) continue;
                mark[t - 1] = 1;
                ++score[t - 1];
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        if (score[i] >= m) {
            result.emplace_back(i + 1);
        }
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        i != 0 && cout << ' ';
        cout << result[i];
    }
    cout << endl;
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