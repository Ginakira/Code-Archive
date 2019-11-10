#include <iostream>
using namespace std;

int main() {
    int n, x = 0, y = 0, z = 0, t1, t2, t3;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2 >> t3;
        x += t1, y += t2, z += t3;
    }
    if (!x && !y && !z) cout << "YES";
    else
        cout << "NO";
    return 0;
}