#include <iostream>
using namespace std;

int w[555], v[555];
int dp[45555];

int main() {
    int h, n;
    cin >> h >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
        v[i] = w[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = h; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}