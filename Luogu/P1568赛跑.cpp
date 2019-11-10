#include <iostream>
using namespace std;

int n, m, pre = 0, v, t;
int sh[1000001], kc[1000001];

int main() {
    cin >> n >> m;
    int tm = 1;
    for(int i = 0; i < n; ++i) {
        cin >> v >> t;
        for(int j = 1; j <= t; ++j, ++tm) {
            sh[tm] = sh[tm - 1] + v;
        }
    }
    tm = 1;
    for(int i = 0; i < m; ++i) {
        cin >> v >> t;
        for(int j = 1; j <= t; ++j, ++tm) {
            kc[tm] = kc[tm - 1] + v;
        }
    }
    for(int i = 1; i <= 27; ++i) {
        cout << "#" << i << ' ' << sh[i] << endl;
    }

    return 0;
}