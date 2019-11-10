#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[1010];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if(i > 0) {
            ans += abs(a[i] - a[i - 1]);
        }
    }
    if (ans == n * (n - 1) / 2) cout << "Jolly";
    else
        cout << "Not jolly";
    return 0;
}