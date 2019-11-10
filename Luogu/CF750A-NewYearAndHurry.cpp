#include <iostream>
using namespace std;

int main() {
    int n, k, ans = 0, left = 240;
    cin >> n >> k;
    left -= k;
    for(int i = 1; i <= n; ++i) {
        if(left >= i * 5) {
            ans++;
            left -= i * 5;
        }
    }
    cout << ans << endl;
    return 0;
}