#include <iostream>
using namespace std;

int a[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0) cout << a[i];
        else cout << ' ' << a[i];
    }
    return 0;
}