// LeetCode 743 网络延迟时间

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Dijkstra最短路
class Solution {
   private:
    static constexpr int INF = INT_MAX / 2;

   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n, vector<int>(n, INF));
        for (auto& time : times) {
            int from = time[0] - 1, to = time[1] - 1, trans_time = time[2];
            graph[from][to] = trans_time;
        }

        vector<int> dis(n, INF);
        vector<int> used(n, 0);

        dis[k - 1] = 0;
        for (int i = 0; i < n; ++i) {
            int current = -1;
            for (int x = 0; x < n; ++x) {
                if (!used[x] && (current == -1 || dis[x] < dis[current])) {
                    current = x;
                }
            }
            used[current] = true;

            for (int to = 0; to < n; ++to) {
                dis[to] = min(dis[to], dis[current] + graph[current][to]);
            }
        }

        int ans = *max_element(dis.begin(), dis.end());
        return ans != INF ? ans : -1;
    }
};