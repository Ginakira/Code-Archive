#include <iostream>
#include <algorithm>
using namespace std;

int house[66] = {0};

int main() {
    int n, h, m;
    cin >> n >> h >> m;
    for(int i = 1; i <= n; ++i) house[i] = h;
    int l, r, x;
    for(int i = 0; i < m; ++i) {
        cin >> l >> r >> x;
        for(int j = l; j <= r; ++j) 
            if(house[j] > x) house[j] = x;
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += house[i] * house[i];
    cout << sum;
    return 0;
}