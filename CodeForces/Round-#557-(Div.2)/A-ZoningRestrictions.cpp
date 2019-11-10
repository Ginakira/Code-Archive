#include <iostream>
using namespace std;

int main() {
    int n, m, h;
    cin >> n >> h >> m;
    int house[51];
    for(int i = 1; i <= n; ++i) house[i] = h;
    for(int i = 1; i <= m; ++i) {
        int l, r, max;
        cin >> l >> r >> max;
        for(int j = l; j <= r; j++) {
            if(house[j] > max) house[j] = max;
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += house[i] * house[i];
    cout << sum << endl;
    return 0;
}