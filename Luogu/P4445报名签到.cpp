#include <iostream>
using namespace std;

int a[100001];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        ans += max(a[i], a[i + 1]);
    }
    cout << ans << endl;
    return 0;
}