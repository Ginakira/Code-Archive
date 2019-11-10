#include <iostream>
using namespace std;

int num[1024], cf[1035];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> num[i];
        cf[i] = num[i] - num[i - 1];
    }
    int l, r, k;
    cin >> l >> r >> k;
    cf[l] += k;
    cf[r + 1] -= k;
    for(int i = 1; i <= n; ++i) {
        num[i] = num[i - 1] + cf[i];
    }
    for(int i = 1; i <= n; ++i) cout << num[i] << ' ';
    return 0;
}