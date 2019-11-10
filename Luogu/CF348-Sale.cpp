#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int a[111];

int main() {
    int n, m, maxp = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int now = 0;
    for (int i = 0; i < m; ++i) {
        now -= a[i];
        maxp = max(now, maxp);
        now = maxp;
    }
    cout << maxp;
    return 0;
}