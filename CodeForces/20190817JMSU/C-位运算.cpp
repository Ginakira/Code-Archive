#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;

LL qpow(LL a, LL n, LL m) {
    LL ans = 0;
    while(n) {
        if(n & 1) {
            ans = (ans + a) % m;
        }
        a = (a + a) % m;
        n >>= 1;
    }
    return ans;
}

int main() {
    LL q, p, t;
    cin >> t;
    while(t--) {
        cin >> q >> p;
        LL a = q - 2, b = q - 1;
        if(q % 2 == 0) a/= 2;
        else b /= 2;
        cout << qpow(a, b, p) << endl;
    }
    return 0;
}