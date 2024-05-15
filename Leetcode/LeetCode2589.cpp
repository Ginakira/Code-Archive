// LeetCode 2589 完成所有任务的最少时间

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
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        ranges::sort(tasks, [](auto& a, auto& b) { return a[1] < b[1]; });
        vector<int> run(tasks[n - 1][1] + 1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            duration -=
                accumulate(run.begin() + start, run.begin() + end + 1, 0);
            ans += max(0, duration);
            for (int j = end; j >= 0 && duration > 0; --j) {
                if (run[j] == 0) {
                    --duration;
                    run[j] = 1;
                }
            }
        }
        return ans;
    }
};