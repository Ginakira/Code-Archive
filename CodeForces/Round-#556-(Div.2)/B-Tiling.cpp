#include <iostream>
using namespace std;


int g[51][51] = {0};
int main() {
    int n;
    int sum = 0;
    char t;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> t;
            if(t == '#') g[i][j] = 1;
            sum += g[i][j];
        }
    }
    if((n * n - sum) % 5 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 2; i < n; ++i) {
        for(int j = 2; j < n; ++j) {
            if(g[i][j]) continue;
            if(!g[i][j]) {
                if(g[i - 1][j] == 0 && g[i + 1][j] == 0 && g[i][j + 1] == 0 && g[i][j - 1] == 0) {
                    g[i - 1][j] = 1;
                    g[i + 1][j] = 1;
                    g[i][j + 1] = 1;
                    g[i][j - 1] = 1;
                    g[i][j] = 1;
                }
            }
        }
    }
    sum = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum += g[i][j];
        }
    }
    if(sum == n * n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}