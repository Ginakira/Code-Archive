#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        long long n, k, ans = 0;
        cin >> n >> k;
        while(n != 0) {
            //cout << "#" << n << ' ' << ans << endl;
            if(n % k == 0) n /= k, ans++;
            else {
                long long tmp = n % k;
                n -= tmp;
                ans += tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}