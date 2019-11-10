#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long x, y, ans = 0;
    long long sum;
    cin >> x >> y;
    sum = x * y;
    int tmp;
    for(int i = x; i <= y; ++i) {
        if(sum % i != 0) continue;
        tmp = sum / i;
        int gcd = __gcd(i, tmp);
        if(gcd == x && sum / gcd == y) ans++;
    }
    cout << ans << endl;

    return 0;
}