#include <iostream>
using namespace std;

char mp[52][52];

int main() {
    int n, m, maxi = -999, maxj = -999, mini = 99, minj = 99;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mp[i][j] = getchar();
            if(mp[i][j] == '*') {
                maxi = max(i, maxi);
                maxj = max(j, maxj);
                mini = min(i, mini);
                minj = min(j, minj);
            }
        }
        //cout << i << ' ' << mini << ' ' << maxi << ' ' << minj << ' ' << maxj
        //     << endl;
        getchar();
    }
    for (int i = mini; i <= maxi; ++i) {
        for (int j = minj; j <= maxj; ++j) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}