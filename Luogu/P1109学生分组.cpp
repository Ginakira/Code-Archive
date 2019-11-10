#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a[55], sum = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int l, r;
    cin >> l >> r;
    if(r * n < sum || sum  < l * n) {
        cout << -1 << endl;
        return 0;
    }
    int add = 0, dele = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > r) add += a[i] - r;
        if(a[i] < l) dele += l - a[i];
    }
    cout << max(add, dele) << endl;
    return 0;
}