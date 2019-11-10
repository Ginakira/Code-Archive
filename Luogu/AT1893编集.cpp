#include <iostream>
using namespace std;
int a[110] = {0};
int main() {
    int n, p;
    cin >> n >> p;
    int l, r, num;
    for(int i = 0; i < p; ++i) {
        cin >> l >> r >> num;
        for(int j = l; j <= r; ++j) {
            a[j] = num;
        }
    }
    for(int i = 1; i <= n; ++i) cout << a[i] << endl;
    return 0;
}