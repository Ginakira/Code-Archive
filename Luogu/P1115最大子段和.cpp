#include <iostream>
#include <algorithm>
using namespace std;

int a[200010], dp[200010];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    sort(dp, dp + n);
    cout << dp[n - 1] << endl; 
    return 0;
}