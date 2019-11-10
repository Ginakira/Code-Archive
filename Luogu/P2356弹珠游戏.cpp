#include <iostream>
using namespace std;

int mp[1001][1001];
struct Point {
    int x, y;
};
Point p[10001];
int main() {
    int n, zero = 0, pcnt = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mp[i][j];
            if(mp[i][j] == 0) {
                zero++;
                p[pcnt].x = i;
                p[pcnt].y = j;
                pcnt++;
            }
        }
    }
    if(zero == 0) {
        cout << "Bad Game!\n";
        return 0;
    }
    int tmp = 0, max = 0;
    for(int i = 0; i < pcnt; ++i) {
        tmp = 0;
        for(int j = 0; j < n; ++j) tmp += mp[p[i].x][j];
        for(int k = 0; k < n; ++k) tmp += mp[k][p[i].y];
        if(max < tmp) max = tmp;
    }
    cout << max << endl;
    return 0;
}