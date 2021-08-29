#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &stone, int cur, int stone_remain, int n, int &ans) {
    if (stone_remain < 0) return;
    if (graph[cur].empty() && stone_remain >= stone[cur]) {
        ++ans;
        return;
    }
    for (auto &next : graph[cur]) {
        dfs(graph, stone, next, stone_remain - stone[next], n, ans);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> stone(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> stone[i];
    }

    for (int i = 1; i <= n - 1; ++i) {
        int temp = 0;
        cin >> temp;
        graph[min(temp, i + 1)].push_back(max(temp, i + 1));
    }
    int ans = 0;
    dfs(graph, stone, 1, m, n, ans);
    cout << ans << endl;
    return 0;
}