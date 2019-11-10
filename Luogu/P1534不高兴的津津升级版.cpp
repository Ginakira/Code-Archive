#include <iostream>
using namespace std;

int main() {
    int n, today, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        today = today + a + b - 8;
        ans += today;
    }
    cout << ans << endl;

    return 0;
}