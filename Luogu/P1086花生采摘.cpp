#include <iostream>
#include <algorithm>
using namespace std;

struct Peanut {
    int x;
    int y;
    int time;
    int num;
};

bool cmp(Peanut a, Peanut b) {
    return a.num > b.num;
}

int gr[50][50];
Peanut p[4000];

int main() {
    int m, n, k, ans, t = 0;
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> gr[i][j];
            if(gr[i][j] > 0) {
                p[t].x = i;
                p[t].y = j;
                p[t].num = gr[i][j];
                ++t;
            }
        }
    }
    sort(p, p + t, cmp);
    for(int i = 0; i < t; ++i) {
        int depth = p[i].x;
        if(i == 0) p[i].time = p[i].x + 1;
        else p[i].time = p[i - 1].time + abs(p[i].x - p[i - 1].x) + abs(p[i].y - p[i - 1].y) + 1;
        if(p[i].time + depth <= k) ans += p[i].num;
    }
    cout << ans << endl;
    return 0;
}