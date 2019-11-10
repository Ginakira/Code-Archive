#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

struct Spice {
    int s, b;
};

Spice sp[15];

bool cmp(Spice a, Spice b) {
    if(a.s == b.s) return a.b > b.b;
    return a.s < b.s;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> sp[i].s;
    for(int i = 0; i < n; ++i) cin >> sp[i].b;
    int minc = INT_MAX;
    int nows = 1, nowb = 0;
    sort(sp, sp + n, cmp);
    for(int i = 0; i < n; ++i) {
        nows *= sp[i].s;
        nowb += sp[i].b;
        minc = min(minc, abs(nows - nowb));
    }
    cout << minc << endl;
    return 0;
}