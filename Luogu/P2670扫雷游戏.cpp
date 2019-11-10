#include <iostream>
using namespace std;

char map[101][101];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(map[i][j] == '*') continue;
            else map[i][j] = '0';
                if(map[i - 1][j] == '*') map[i][j]++;
                if(map[i + 1][j] == '*') map[i][j]++;
                if(map[i - 1][j + 1] == '*') map[i][j]++;
                if(map[i + 1][j + 1] == '*') map[i][j]++;
                if(map[i][j - 1] == '*') map[i][j]++;
                if(map[i][j + 1] == '*') map[i][j]++;
                if(map[i - 1][j - 1] == '*') map[i][j]++;
                if(map[i + 1][j - 1] == '*') map[i][j]++;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}