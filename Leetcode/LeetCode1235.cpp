// LeetCode 1235 规划兼职工作

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<int> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back(i);
        }
        // 将索引按结束时间升序排序
        sort(jobs.begin(), jobs.end(),
             [&](int a, int b) { return endTime[a] < endTime[b]; });
        // 为了方便二分查找 将结束时间也升序排序
        sort(endTime.begin(), endTime.end());
        // dp[i]为到索引i的任务可获得的最大收益
        vector<int> dp(n);
        dp[0] = profit[jobs[0]];
        for (int i = 1; i < n; ++i) {
            // 找到结束时间第一个大于当前任务开始时间的
            // 它的前一个位置就是最后一个比当前任务开始时间小或者等于的任务
            int ind = upper_bound(endTime.begin(), endTime.end(),
                                  startTime[jobs[i]]) -
                      endTime.begin() - 1;
            // 选择当前任务能获得的收益
            int choose = (ind == -1 ? 0 : dp[ind]) + profit[jobs[i]];
            // 不选择获得的收益
            int not_choose = dp[i - 1];
            dp[i] = max(not_choose, choose);
        }
        return dp[n - 1];
    }
};