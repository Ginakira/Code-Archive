#include <iostream>
using namespace std;

char f[110][110];

int main() {
    int n, m;
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = getchar();
        }
        getchar();
    }
    for (int i = 1; i <= n; ++i) {
        char hc = f[i][1];
        for (int j = 1; j <= m; ++j) {
            if(f[i][j] != hc || f[i][j] == f[i - 1][j] || f[i][j] == f[i + 1][j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}