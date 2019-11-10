#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int map[110][110], dis[110];
bool vis[110] = {false};

int dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        dis[i] = map[1][i];
    }
    vis[1] = true;
    dis[1] = 0;
    int min_pos = 1;
    for (int i = 1; i < n; ++i) {
        int min = INF;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dis[j] < min) {
                min_pos = j;
                min = dis[j];
            }
        }
        vis[min_pos] = true;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dis[j] > dis[min_pos] + map[min_pos][j]) {
                dis[j] = dis[min_pos] + map[min_pos][j];
            }
        }
    }
    return dis[n];
}

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = INF;
            }
        }
        int s, e, v;
        for (int i = 0; i < m; ++i) {
            cin >> s >> e >> v;
            if (v < map[s][e]) {
                map[s][e] = map[e][s] = v;
            }
        }
        cout << dijkstra() << endl;
    }
    return 0;
}