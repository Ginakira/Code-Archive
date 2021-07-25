// LeetCode 1743 从相邻元素对还原数组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> edges;
        for (auto &adj_pair : adjacentPairs) {
            edges[adj_pair[0]].push_back(adj_pair[1]);
            edges[adj_pair[1]].push_back(adj_pair[0]);
        }

        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        for (auto &[e, adj] : edges) {
            if (adj.size() == 1) {
                result[0] = e;
                break;
            }
        }

        result[1] = edges[result[0]][0];
        for (int i = 2; i < n; ++i) {
            auto &adj = edges[result[i - 1]];
            result[i] = adj[0] == result[i - 2] ? adj[1] : adj[0];
        }
        return result;
    }
};