#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, r;
    int buy_min = 1001, sell_max = -1;
    cin >> n >> m >> r;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if(t < buy_min) buy_min = t;
    }
    for(int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if(t > sell_max) sell_max = t;
    }
    //cout << buy_min << endl << sell_max << endl;
    if(buy_min > sell_max) cout << r << endl;
    else {
        int t = r;
        int cnt = t / buy_min;
        r -= cnt * buy_min;
        r += cnt * sell_max;
        cout << r << endl;
    }
    return 0;
}