#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;

int main() {
    LL a, b, c, tmp, n[4];
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n + 3);
    a = n[0], b = n[1], c = n[2];
    tmp = a * b / __gcd(a, b);
    LL ans;
    ans = tmp * c / __gcd(tmp, c);
    cout << ans << endl;
    return 0;
}