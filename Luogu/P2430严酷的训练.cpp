#include <iostream>
using namespace std;

int w[5050], v[5050], dp[5050];
int tm[5050];

int main() {
    int ws, ls, m, n;
    cin >> ws >> ls >> m >> n;
    int plus = ls / ws;
    for(int i = 1; i <= n; ++i) {
        cin >> tm[i];
        tm[i] *= plus;
    }
    int pt;
    for(int i = 1; i <= m; ++i) {
        cin >> pt >> v[i];
        w[i] = tm[pt];
    }
    int tm_lim;
    cin >> tm_lim;
    for(int i = 1; i <= m; ++i) {
        for(int j = tm_lim; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[tm_lim] << endl;
    return 0;
}