// LeetCode 1462 课程表IV

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>> &prerequisites,
                                     vector<vector<int>> &queries) {
        std::vector<std::vector<int>> g(numCourses);
        std::vector<std::vector<bool>> is_dependency(
            numCourses, std::vector<bool>(numCourses, false));
        std::vector<int> in_deg(numCourses, 0);

        for (auto &pre : prerequisites) {
            int u = pre[0], v = pre[1];
            g[u].emplace_back(v);
            ++in_deg[v];
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in_deg[i] == 0) {
                q.emplace(i);
            }
        }
        while (!q.empty()) {
            auto course = q.front();
            q.pop();
            for (auto &e : g[course]) {
                is_dependency[course][e] = true;
                for (int i = 0; i < numCourses; ++i) {
                    is_dependency[i][e] =
                        is_dependency[i][e] || is_dependency[i][course];
                }
                if (--in_deg[e] == 0) {
                    q.emplace(e);
                }
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &query : queries) {
            ans.emplace_back(is_dependency[query[0]][query[1]]);
        }
        return ans;
    }
};
