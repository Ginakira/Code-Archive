#include <iostream>
using namespace std;

int mp[150][150], cnt[150][150];
int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < x; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int xi = x1; xi <= x2; ++xi) {
            for(int yi = y1; yi <= y2; ++yi) {
                mp[xi][yi]++;
                cnt[xi][yi] = i + 1;
            }
        }
    }
    for(int i = 0; i < y; ++i) {
        int xk, yk;
        cin >> xk >> yk;
        if(!mp[xk][yk]) cout << "N\n";
        else cout << "Y " << mp[xk][yk] << ' ' << cnt[xk][yk] << endl;
    }
    return 0;
}