#include <iostream>
using namespace std;

int w[110], v[110];
int dp[110];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
        v[i] = w[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}