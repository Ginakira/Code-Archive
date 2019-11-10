#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int pre[30];
struct Edge {
    int u, v, w;
};

Edge edge[80];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

int find(int key) {
    if(pre[key] == key) return key;
    return pre[key] = find(pre[key]);
}

int main() {
    int n;
    while(cin >> n && n) {
        for (int i = 0; i < 30; ++i) {
            pre[i] = i;
        }
        int k = 0;
        for (int i = 0; i < n - 1; ++i) {
            char c1;
            int cnt;
            cin >> c1 >> cnt;
            for (int j = 0; j < cnt; ++j, ++k) {
                int m;
                char c2;
                cin >> c2 >> m;
                edge[k].u = c1 - 'A';
                edge[k].v = c2 - 'A';
                edge[k].w = m;
            }
        }
        sort(edge, edge + k, cmp);
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int x = find(edge[i].u);
            int y = find(edge[i].v);
            if(x != y) {
                ans += edge[i].w;
                pre[x] = y;
            }
        }
        cout << ans << endl;
    }
    return 0;
}