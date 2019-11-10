#include <iostream>
using namespace std;

char mp[510][510];

int main() {
    int r, c;
    cin >> r >> c;
    getchar();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mp[i][j] = getchar();
        }
        getchar();
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mp[i][j] == 'S') {
                if (mp[i - 1][j] == 'W' || mp[i + 1][j] == 'W' ||
                    mp[i][j - 1] == 'W' || mp[i][j + 1] == 'W') {
                    cout << "No\n";
                    return 0;
                }
                else {
                    if (mp[i - 1][j] == '.') mp[i - 1][j] = 'D';
                    if (mp[i + 1][j] == '.') mp[i + 1][j] = 'D';
                    if (mp[i][j - 1] == '.') mp[i][j - 1] = 'D';
                    if (mp[i][j + 1] == '.') mp[i][j + 1] = 'D';
                }
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)  {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}