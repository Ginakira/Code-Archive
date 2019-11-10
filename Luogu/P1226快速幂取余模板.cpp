#include <iostream>
using namespace std;
typedef long long LL;

LL qPow(int a, int b, int m = 1) {
    LL ans = 1, base = a;
    while(b > 0) {
        if(b & 1) {
            ans *= base;
            ans %= m;
        }
        base *= base;
        base %= m;
        b >>= 1;
    }
    return ans;
}

int main() {
    LL b, p, k, ans;
    cin >> b >> p >> k;
    if(p == 0) ans = 1 % k;
    else ans = qPow(b, p, k);
    cout << b << '^' << p << " mod " << k << '=' << ans << endl;
    return 0;
}