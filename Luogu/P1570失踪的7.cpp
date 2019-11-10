#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n, t, ans = 0;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(ll p = 1; n != 0; p *= 9) {
            int tmp = n % 10;
            if(tmp >= 7) tmp--;
            ans += tmp * p;
            n /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}