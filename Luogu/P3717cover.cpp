#include <iostream>
#include <cmath>
using namespace std;

int mp[110][110] = {0};

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    int x, y;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        double dis;
        for(int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                dis = sqrt((x - j) * (x - j) + (y - k) * (y - k));
                if(dis <= r) mp[j][k] = 1;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum += mp[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}