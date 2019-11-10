#include <iostream>
using namespace std;

int w[50555], v[50555];
int dp[50555];

int main() {
    int c, h;
    cin >> c >> h;
    for(int i = 1; i <= h; ++i) {
        cin >> w[i];
        v[i] = w[i];
    }
    for(int i = 1; i <= h; ++i) {
        for(int j = c; j >= w[i]; --j) {
            if(dp[j] == c) {
                cout << c << endl;
                return 0;
            }
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}