#include <algorithm>
#include <iostream>
using namespace std;

int pre[110];

int find(int key) {
    if (pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        pre[i] = i;
    }
}

struct Road {
    int s, e, cost;
    bool operator<(const Road &a) const { return cost < a.cost; }
};

Road r[6010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n && n) {
        int tmp = n * (n - 1) / 2;
        for(int i = 0; i < tmp; ++i) {
            cin >> r[i].s >> r[i].e >> r[i].cost;
        }
        sort(r, r + tmp);
        init(n);
        int ans = 0;
        for(int i = 0; i < tmp; ++i) {
            int ra = find(r[i].s);
            int rb = find(r[i].e);
            if(ra != rb) {
                pre[ra] = rb;
                ans += r[i].cost;
            }
        }
        cout << ans << endl;
    }
    return 0;
}