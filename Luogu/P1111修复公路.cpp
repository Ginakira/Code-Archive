#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 100010

int ans, pre[MAXN];

struct Road {
    int u, v, w;
};

Road road[MAXN];

bool cmp(Road a, Road b) { return a.w < b.w; }

void init() {
    for (int i = 1; i <= MAXN; ++i) {
        pre[i] = i;
    }
    return;
}
int find(int key) {
    if (pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

void merge(Road a, int para = 0) {
    int ra = find(a.u);
    int rb = find(a.v);
    if (ra != rb) {
        pre[ra] = rb;
        if (para == 1) {
            ans = max(ans, a.w);
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        cin >> road[i].u >> road[i].v >> road[i].w;
        merge(road[i], 0);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (pre[i] == i) cnt++;
    }
    if (cnt > 1) {
        cout << -1;
        return 0;
    }
    sort(road, road + m, cmp);
    init();
    for (int i = 0; i < m; ++i) {
        merge(road[i], 1);
    }
    cout << ans << endl;
    return 0;
}