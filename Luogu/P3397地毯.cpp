#include <iostream>
using namespace std;

int a[1001][1001] = {0};

int main() {
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <= x2; ++j) {
            for(int k = y1; k <= y2; ++k) {
                a[j][k]++;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}