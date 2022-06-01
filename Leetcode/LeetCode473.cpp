// LeetCode 473 火柴拼正方形

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool dfs(int index, const vector<int> &matchsticks, array<int, 4> &edges,
             int target) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (size_t i = 0; i < 4; ++i) {
            if (edges[i] + matchsticks[index] > target) continue;
            if (i > 0 && edges[i] == edges[i - 1]) continue;
            edges[i] += matchsticks[index];
            if (dfs(index + 1, matchsticks, edges, target)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

   public:
    bool makesquare(vector<int> &matchsticks) {
        int sum_len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum_len % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        array<int, 4> edges{0};
        return dfs(0, matchsticks, edges, sum_len / 4);
    }
};