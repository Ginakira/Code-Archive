#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool mark[10010];

int main() {
    int l, m;
    cin >> l >> m;
    int s, e;
    memset(mark, true, sizeof(mark));
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        for (int j = s; j <= e; ++j) {
            mark[j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i <= l; ++i) {
        if (mark[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}