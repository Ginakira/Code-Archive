#include <iostream>
using namespace std;

int c[6666], w[6666];
int dp[13999];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i] >> w[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}