#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

unsigned long long a[333];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        unsigned long long ans = a[0] * a[n - 1];
        bool flag = true;
        for(int i = 1; i < n / 2 && flag; ++i) {
            if(a[i] * a[n - 1 - i] != ans) {
                flag = false;
                break;
            }
        }
        if(n % 2 == 1) {
            if(a[n / 2] * a[n / 2] != ans) flag = false;
        }
        if(flag) {
            int tmp = 0;
            for(int i = 2; i < sqrt(ans); ++i) {
                if(ans % i == 0) tmp += 2;
            }
            if((long long) sqrt(ans) * sqrt(ans) == ans) tmp++;
            if(tmp != n) flag = false;
        }
        if(!flag) {
            cout << -1 << endl;
        }
        else cout << ans << endl;
    }
    return 0;
}