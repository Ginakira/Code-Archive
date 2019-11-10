#include <iostream>
using namespace std;


int main() {
    long long n, x, pre, now;
    cin >> n >> x;
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            cin >> pre;
            if(pre > x) {
                ans += pre - x;
                pre = x;
            }
            continue;
        }
        else {
            cin >> now;
            if(now + pre > x) {
                ans += now + pre - x;
                now -= now + pre - x;
            }
            pre = now;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}