#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double ans[33], money;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> money;
            ans[j] += money;
        }
    }
    //cout << setiosflags(ios::fixed) << setprecision(1);
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}