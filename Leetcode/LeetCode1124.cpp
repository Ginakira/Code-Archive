// LeetCode 1124 表现良好的最长时间段

#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int ans = 0;
        vector<int> pre_sum(n + 1, 0);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (pre_sum[stk.top()] > pre_sum[i]) {
                stk.push(i);
            }
        }
        for (int i = n; i > 0; --i) {
            while (!stk.empty() && pre_sum[i] > pre_sum[stk.top()]) {
                ans = max(ans, i - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};