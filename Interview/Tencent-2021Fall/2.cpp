// AC
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<long long> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }
    sort(balls.rbegin(), balls.rend());
    long long add = 0, ans = 0;

    for (int ball : balls) {
        ball = (ball + add) % MOD;
        ans = (ans + ball) % MOD;
        add = (ball + add) % MOD;
    }

    cout << ans << endl;
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