#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    int mp[n + 5][n + 5];
    memset(mp, 0, sizeof(mp));
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        mp[x][y] = 1;
        mp[x][y - 1] = 1;
        mp[x][y - 2] = 1;
        mp[x][y + 1] = 1;
        mp[x][y + 2] = 1;
        mp[x - 1][y] = 1;
        mp[x - 2][y] = 1;
        mp[x + 1][y] = 1;
        mp[x + 2][y] = 1;
        mp[x - 1][y - 1] = 1;
        mp[x - 1][y + 1] = 1;
        mp[x + 1][y + 1] = 1;
        mp[x + 1][y - 1] = 1;
    }
    for(int i = 0; i < k; ++i) {
        cin >> x >> y;
        for(int i = x - 2; i <= x + 2; ++i) {
            for(int j = y - 2; j <= y + 2; ++j) {
                mp[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(mp[i][j] == 0) ans++;
            //cout << mp[i][j];
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}