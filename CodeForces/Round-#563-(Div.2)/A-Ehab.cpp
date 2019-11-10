#include <iostream>
#include <algorithm>
using namespace std;

int a[2020];
int main() {
    int n, sump = 0, sumb = 0;
    cin >> n;
    for(int i = 0; i < 2 * n; ++i) cin >> a[i];
    sort(a, a + 2 * n);
    for(int i = 0; i < n; ++i) sump += a[i];
    for(int i = n; i < 2 * n; ++i) sumb += a[i];
    if(sumb == sump) {
        cout << -1 << endl;
        return 0;
    }
    else {
        for(int i = 0; i < 2 * n; ++i) {
            if(i == 0) cout << a[i];
            else cout << ' ' << a[i];
        }
        cout << endl;
    }
    return 0;
}