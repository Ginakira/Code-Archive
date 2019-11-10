#include <algorithm>
#include <iostream>
using namespace std;

int a[3030];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] != i) {
            cout << i;
            return 0;
        }
    }
    cout << n + 1;
    return 0;
}