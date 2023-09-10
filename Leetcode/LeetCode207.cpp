// LeetCode 207 课程表
#include <queue>
#include <vector>
using namespace std;

// 基于BFS的拓扑排序，同LC210
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (auto &pre : prerequisites) {
            int u = pre[1], v = pre[0];
            edges[u].emplace_back(v);
            ++in_degree[v];
        }

        queue<int> q;
        for (int i = 0; auto &d : in_degree) {
            if (d == 0) {
                q.emplace(i);
            }
            ++i;
        }

        int cnt = 0;
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            ++cnt;
            for (auto &e : edges[i]) {
                if (--in_degree[e] == 0) {
                    q.emplace(e);
                }
            }
        }
        return cnt == numCourses;
    }
};