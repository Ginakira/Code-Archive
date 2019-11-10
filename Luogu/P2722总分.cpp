#include <iostream>
using namespace std;

int w[100001], v[100001], dp[10001];

int main() {
    int n, m;
    cin >> m >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = w[i]; j <= m; ++j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
}