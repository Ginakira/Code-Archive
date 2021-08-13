#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for (int i = n - 1; i >= 0; i -= 2) {
        if (i == 0) {
            ans += num[0];
            break;
        } else if (i == 1) {
            ans += num[1];
            break;
        } else if (i == 2) {
            ans += num[0] + num[1] + num[2];
            break;
        }
        ans += min(num[1] + num[0] + num[i] + num[1],
                   num[i] + num[0] + num[i - 1] + num[0]);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}