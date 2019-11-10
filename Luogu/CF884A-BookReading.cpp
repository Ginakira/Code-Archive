#include <iostream>
using namespace std;

int a[233];

int main() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if(86400 - a[i] >= t) {
            cout << ans;
            return 0;
        }
        t -= 86400 - a[i];
        ++ans;
    }
    cout << ans;
    return 0;
}