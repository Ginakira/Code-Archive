// LeetCode 797 所有可能的路径

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> path;

    void dfs(int from, int n, vector<vector<int>> &graph,
             vector<vector<int>> &result) {
        if (from == n - 1) {
            result.emplace_back(path);
            return;
        }
        for (auto &to : graph[from]) {
            path.push_back(to);
            dfs(to, n, graph, result);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> result;
        path.push_back(0);
        dfs(0, n, graph, result);
        return result;
    }
};