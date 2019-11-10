#include <cstring>
#include <iostream>
using namespace std;
int main() {
    long long live[1000], grow[1000];
    int t, n, d, a, k, x;
    cin >> t;
    while (t--) {
        memset(live, 0, sizeof(live));
        memset(grow, 0, sizeof(grow));
        cin >> n >> d >> a >> k >> x;
        grow[0] = n;
        long long ans = 0;
        for (int i = 0; i < x; i++) {
            for (int j = i; j < i + a; j++) {
                grow[j + k + 1] += grow[i];
            }
            for (int j = i; j < i + d; j++) {
                live[j] += grow[i];
            }
            ans += 5 * live[i];
        }
        cout << ans << endl;
    }
    return 0;
}