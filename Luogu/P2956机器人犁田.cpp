#include <iostream>
#include <algorithm>
using namespace std;

bool f[241][241];
int main() {
    int x, y, op;
    cin >> x >> y >> op;
    int xl, yl, xr, yr;
    for(int i = 0; i < op; ++i) {
        cin >> xl >> yl >> xr >> yr;
        for(int xn = xl; xn <= xr; ++xn) {
            for(int yn = yl; yn <= yr; ++yn) {
                f[xn][yn] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= x; ++i) {
        for(int j = 1; j <= y; ++j) {
            ans += f[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}