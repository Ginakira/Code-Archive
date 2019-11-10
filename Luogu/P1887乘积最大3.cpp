#include <iostream>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    ans = n / m;
    int remain = n % m;
    for(int i = 0; i < m - remain; ++i) cout << ans << ' ';
    for(int i = 0; i < remain; ++i) cout << ans + 1 << ' ';
    return 0;
}