// LeetCode 207 课程表
#include <queue>
#include <vector>
using namespace std;

// 基于BFS的拓扑排序，同LC210
class Solution {
   private:
    vector<vector<int>> edges;
    vector<int> indeg;

   public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto &info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ret;
        while (!q.empty()) {
            int u = q.front();
            for (auto &v : edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
            ret.push_back(u);
            q.pop();
        }
        if (ret.size() != numCourses) return false;
        return true;
    }
};