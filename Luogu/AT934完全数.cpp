#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL cal(LL n) {
    LL sum = 0;
    for(LL i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            sum += i;
            sum += n / i;
        }
        if(i * i == n && n % i == 0) sum -= i;
    }
    return sum + 1;
}

int main() {
    LL n;
    cin >> n;
    if(n == 1) {
        cout << "Deficient\n";
        return 0;
    }
    LL ans = cal(n);
    //cout << ans << endl;
    if(ans == n) cout << "Perfect\n";
    else if(ans < n) cout << "Deficient\n";
    else cout << "Abundant\n";
    return 0;
}