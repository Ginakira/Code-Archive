#include <iostream>
using namespace std;

int w[111], v[111];
int dp[111][1111];
int main() {
    int t, m;
    cin >> t >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = t; j >= 0; --j) {
            if(w[i] > j) dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}