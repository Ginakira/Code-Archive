// LeetCode 2398 预算内的最多机器人数目

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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        int n = chargeTimes.size();
        long long cur_sum = 0;
        int ans = 0;
        deque<int> q;
        for (int i = 0, j = 0; i < n; ++i) {
            cur_sum += runningCosts[i];
            while (!q.empty() && chargeTimes[q.back()] <= chargeTimes[i]) {
                q.pop_back();
            }
            q.push_back(i);
            while (j <= i &&
                   (i - j + 1) * cur_sum + chargeTimes[q.front()] > budget) {
                if (!q.empty() && q.front() == j) {
                    q.pop_front();
                }
                cur_sum -= runningCosts[j];
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};