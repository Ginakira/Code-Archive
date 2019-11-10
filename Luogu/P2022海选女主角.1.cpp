#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    while(cin >> m >> n) {
        int max, ans, max_row = 0, max_column = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int t;
                cin >> t;
                if(i == 0 && j == 0) max = t;
                if(abs(t) > max) {
                    max = abs(t);
                    ans = t;
                    max_row = i + 1;
                    max_column = j + 1;
                }
            }
        }
        cout << max_row << ' ' << max_column << ' ' << ans << endl;
    }
    return 0;
}