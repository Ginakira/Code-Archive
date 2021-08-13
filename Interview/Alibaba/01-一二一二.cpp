#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> scores(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    vector<int> dp(n, 0);
    dp[0] = scores[0];
    if (n >= 2) dp[1] = (int)floor(scores[1] / 2.0);
    for (int i = 2; i < n; ++i) {
        int one_step = (int)floor(scores[i] / 2.0) + dp[i - 1];
        int two_step = scores[i] + dp[i - 2];
        dp[i] = max(one_step, two_step);
    }
    cout << dp[n - 1] << endl;
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