// LeetCode 210 课程表II
#include <algorithm>
#include <vector>
using namespace std;

// 基于DFS的拓扑排序
class Solution {
   private:
    enum status { NOT_SEARCHED, SEARCHING, SEARCHED };
    vector<vector<int>> edges;
    vector<status> visited;
    vector<int> result;
    bool valid = true;

   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (visited[i] == NOT_SEARCHED) {
                dfs(i);
            }
        }
        if (!valid) return {};
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(int u) {
        visited[u] = SEARCHING;
        for (int v : edges[u]) {
            if (visited[v] == SEARCHING) {
                valid = false;
                return;
            } else if (visited[v] == NOT_SEARCHED) {
                dfs(v);
                if (!valid) return;
            }
        }
        visited[u] = SEARCHED;
        result.push_back(u);
        return;
    }
};