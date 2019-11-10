#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = n; i <= m; ++i) {
        if(i % 2 != 0 || i % 4 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}