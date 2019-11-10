#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Player {
    int num, score;
};

bool cmp(Player a, Player b) {
    if(a.score == b.score) return a.num < b.num;
    return a.score > b.score;
}

Player p[5005];
int main() {
    int n;
    double m;
    cin >> n >> m;
    m = floor(m * 1.5);
    for(int i = 0; i < n; ++i) cin >> p[i].num >> p[i].score;
    sort(p, p + n, cmp);
    int line = p[int(m) - 1].score;
    int j;
    for(j = 0; p[j].score >= line; ++j);
    cout << p[int(m) - 1].score << ' ' << j << '\n';
    for(int i = 0; i < j; ++i) {
        cout << p[i].num << ' ' << p[i].score << '\n';
    }
    return 0;
}