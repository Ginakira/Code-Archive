#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, m, ta, tb, k;
LL a[200001], b[200001];
int main() {
    cin >> n >> m >> ta >> tb >> k;
    for(LL i = 1; i <= n; ++i) cin >> a[i], a[i] += ta;
    for(LL i = 1; i <= m; ++i) cin >> b[i];
    if(k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    LL ans = -1;
    for(int i = 1; i <= n && i <= k + 1; ++i) {
        int ind = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        ind += k - i + 1;
        if(ind > m) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, b[ind] + tb);
    }
    cout << ans << endl;
    return 0;
}