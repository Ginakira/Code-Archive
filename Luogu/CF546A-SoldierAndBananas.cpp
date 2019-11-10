#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int w, k, n;
    cin >> k >> n >> w;
    for(int i = 1; i <= w; ++i) {
        n -= i * k;
    }
    if(n < 0) cout << abs(n);
    else cout << 0;
    return 0;
}