// LeetCode 210 课程表II
#include <algorithm>
#include <queue>
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

// 基于BFS的拓扑排序，统计入度，每次删除入度0的边，加入答案
class Solution2 {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (auto& pre : prerequisites) {
            int u = pre[1], v = pre[0];
            edges[u].emplace_back(v);
            ++in_degree[v];
        }

        queue<int> q;
        for (int i = 0; auto& d : in_degree) {
            if (d == 0) {
                q.emplace(i);
            }
            ++i;
        }

        vector<int> ans;
        ans.reserve(numCourses);
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            ans.emplace_back(i);
            for (auto& e : edges[i]) {
                if (--in_degree[e] == 0) {
                    q.emplace(e);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>{};
    }
};