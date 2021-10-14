#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

// AC
int main() {
    int n;
    cin >> n;
    vector<vector<int>> rooms(n);
    for (int i = 0; i < n; ++i) {
        rooms[i].resize(i + 1);
        for (int j = 0; j < i + 1; ++j) {
            cin >> rooms[i][j];
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            int num = rooms[i][j];
            if (j - 1 >= 0) {
                rooms[i][j] = max(rooms[i][j], num + rooms[i][j - 1]);
            }
            if (i - 1 >= 0) {
                rooms[i][j] = max(rooms[i][j], num + rooms[i - 1][j]);
            }
        }
    }
    LL max_ans = 0;
    for (int i = 0; i <= n - 1; ++i) {
        LL num = rooms[n - 1][i];
        if (n - 2 >= 0) {
            num += rooms[n - 2][i];
        }
        max_ans = max(max_ans, num);
    }
    cout << max_ans << endl;
    return 0;
}