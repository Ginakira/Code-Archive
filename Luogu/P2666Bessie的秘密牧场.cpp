#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tmp = n;
    n = sqrt(n);
    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            for(int k = 0; k <= n; ++k) {
                for(int m = 0; m <= n; ++m) {
                    if(i * i + j * j + k * k + m * m == tmp) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}