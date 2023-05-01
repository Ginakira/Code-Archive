// LeetCode 1376 通知所有员工所需的时间

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
   private:
    int ans = 0;
    unordered_map<int, vector<int>> subordinates;

    void dfs(int n, vector<int>& informTime, int cur_id, int cur_time) {
        auto& subordinate = subordinates[cur_id];
        if (subordinate.empty()) {
            ans = max(ans, cur_time);
        }
        int inform = informTime[cur_id];
        for (auto sub : subordinate) {
            dfs(n, informTime, sub, cur_time + inform);
        }
    }

   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        for (int i = 0; i < n; ++i) {
            subordinates[manager[i]].emplace_back(i);
        }
        dfs(n, informTime, headID, 0);
        return ans;
    }
};