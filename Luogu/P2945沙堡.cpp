#include <iostream>
#include <algorithm>
using namespace std;

int m[25001], b[25001];
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; ++i) {
        cin >> m[i] >> b[i];
    }
    sort(m, m + n);
    sort(b, b + n);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(m[i] - b[i] > 0) ans += y * (m[i] - b[i]);
        else ans += x * (b[i] - m[i]);
    }
    cout << ans << endl;
    return 0;
}