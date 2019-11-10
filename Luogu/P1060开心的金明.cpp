#include <iostream>
using namespace std;

int w[55], v[55];
int dp[30023];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> w[i];
        cin >> v[i];
        v[i] *= w[i];
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = n; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}