#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[10010];

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a + l1 - 1, a + r1);
    sort(a + l2 - 1, a + r2, greater<int>());
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    return 0;
}