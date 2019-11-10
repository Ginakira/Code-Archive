#include <iostream>
using namespace std;

int a[1010];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if(i != 0 && i != n - 1) {
            if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                ans++;
        }
    }
    cout << ans;
    return 0;
}