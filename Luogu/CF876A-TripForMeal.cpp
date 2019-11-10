#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    if(min(a, b) <= c) cout << (n - 1) * min(a, b);
    else cout << min(a, b) + (n - 2) * c;
    return 0;
}