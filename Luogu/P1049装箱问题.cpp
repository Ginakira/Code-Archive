#include <iostream>
using namespace std;

int w[33];
int dp[20022];

int main() {
    int v, n;
    cin >> v >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = v; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}