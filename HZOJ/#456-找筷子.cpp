#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[1000010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans ^= a[i];
    }
    cout << ans << endl;
    return 0;
}