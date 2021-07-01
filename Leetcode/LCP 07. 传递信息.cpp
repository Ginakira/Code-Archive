// LCP 07. 传递信息
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        int ans = 0;

        unordered_map<int, vector<int>> edges;
        for (auto &r : relation) {
            int from = r[0], to = r[1];
            edges[from].push_back(to);
        }

        queue<tuple<int, int>> que;
        que.emplace(0, 0);

        while (!que.empty()) {
            auto [current, steps] = que.front();
            que.pop();

            if (steps == k) {
                ans += (current == n - 1) ? 1 : 0;
                continue;
            }

            for (auto &next : edges[current]) {
                que.emplace(next, steps + 1);
            }
        }

        return ans;
    }
};