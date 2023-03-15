// LeetCode 1615 最大网络秩

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<vector<bool>> is_connected(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (auto& road : roads) {
            int e = road[0], v = road[1];
            is_connected[e][v] = true;
            is_connected[v][e] = true;
            ++degree[e];
            ++degree[v];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans,
                          degree[i] + degree[j] - (is_connected[i][j] ? 1 : 0));
            }
        }
        return ans;
    }
};