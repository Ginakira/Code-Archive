#include <iostream>
using namespace std;

int main() {
    int n, d, pre, now, ans = 0;
    cin >> n >> d;
    cin >> pre;
    for (int i = 0; i < n - 1; ++i) {
        cin >> now;
        if (now <= pre)  {
            int add = (pre - now) / d + 1;
            ans += add, now += add * d;
        }
        pre = now;
    }
    cout << ans;
    return 0;
}