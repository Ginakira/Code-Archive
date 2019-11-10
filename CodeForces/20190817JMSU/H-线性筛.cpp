#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    if(!b) return a;
    return gcd(b, a % b);
}

LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

int main() {
    int I, a, m;
    while(cin >> I >> a && (I || a)) {
        LL ans = 1;
        for(int i = 0; i < I; ++i) {
            cin >> m;
            ans = lcm(ans, m);
        }
        cout << ans - a << endl;
    }
    return 0;
}