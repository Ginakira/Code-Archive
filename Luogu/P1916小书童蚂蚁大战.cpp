#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[10001];

int main() {
    int n, m, k, w, r;
    cin >> n >> m >> k >> w >> r;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int max_att = m / k * w;
    int sec = 0, i = 0;
    while(sec < r) {
        if(a[i] <= 0) i++;
        a[i] -= max_att;
        sec++;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}