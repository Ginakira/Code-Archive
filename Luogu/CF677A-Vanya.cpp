#include <iostream>
using namespace std;

int main() {
    int n, k, tmp, ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp > k) ans += 2;
        else ans++;
    }
    cout << ans;
    return 0;
}