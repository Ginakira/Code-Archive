#include <iostream>
#include <algorithm>
using namespace std;

int a[200001];
int main() {
    int n, t;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t < 0) t = 0 - t;
        a[i] = t;
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] + a[j] >= a[j] && a[j] - a[i] <= a[i]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}