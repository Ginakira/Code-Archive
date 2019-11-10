#include <iostream>
using namespace std;

int a[10010];
int main() {
    int n, maxw = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l, r;
    for(int i = 0; i < n; ++i) {
        l = i, r = i;
        while(a[l - 1] <= a[l] && l > 0) l--;
        while(a[r + 1] <= a[r] && r < n - 1) r++;
        //cout << "# " << l << ' ' << r << ' ' << r - l + 1 << endl;
        maxw = max(maxw, r - l + 1);
    }
    cout << maxw << endl;
    return 0;
}