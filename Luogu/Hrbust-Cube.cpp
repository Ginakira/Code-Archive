#include <bits/stdc++.h>
using namespace std;

struct Cube {
    int a, b, c;
    int s, v;
};Cube cub[100];

bool cmp(Cube a, Cube b) {
    return a.s < b.s;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cub[i].a >> cub[i].b >> cub[i].c;
        cub[i].s = ((2 * cub[i].a * cub[i].b) + (2 * cub[i].b * cub[i].c) + (2 * cub[i].c * cub[i].a));
        cub[i].v = cub[i].a * cub[i].b * cub[i].c;
    }
    sort(cub, cub+n, cmp);
    for (int i = 0; i < n; i++) {
        cout << cub[i].a << ":" << cub[i].b << ":" << cub[i].c << " " << cub[i].s  << ' ' << cub[i].v << endl;
    }
    return 0;
}