#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int a[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int line = a[n / 2], cnt = n / 2 + 1;
    for (int i = n / 2 + 1; i < n; ++i) {
        if (a[i] == line)
            cnt++;
        else
            break;
    }
    cout << line << ' ' << cnt;
    return 0;
}