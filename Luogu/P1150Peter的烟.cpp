#include <iostream>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    ans += n;
    while(n >= k) {
        ans += n / k;
        n = n / k + n % k;
    }
    cout << ans << '\n';

    return 0;
}