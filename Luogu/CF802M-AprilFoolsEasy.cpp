#include <iostream>
#include <algorithm>
using namespace std;

int a[2333];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += a[i];
    cout << sum;
    return 0;
}