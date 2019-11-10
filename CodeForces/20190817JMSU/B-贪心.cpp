#include <iostream>
#include <algorithm>
using namespace std;

struct Tv{
    int s, e;
};

Tv tv[110];

bool cmp(Tv a, Tv b) { return a.e < b.e; }

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) continue;
        for (int i = 0; i < n; ++i) {
            cin >> tv[i].s >> tv[i].e;
        }
        sort(tv, tv + n, cmp);
        int ans = 1, pre = tv[0].e;
        for (int i = 1; i < n; ++i) {
            if (tv[i].s >= pre) {
                ans++;
                pre = tv[i].e;
            }
        }
        cout << ans << endl;
    }
    return 0;
}