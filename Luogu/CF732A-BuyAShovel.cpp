#include <iostream>
using namespace std;

int main() {
    long long k, r, ans = 1;
    cin >> k >> r;
    int tmp = k;
    while (k % 10 != r && k % 10 != 0) {
        ans++;
        k += tmp;
    }
    cout << ans;
    return 0;
}