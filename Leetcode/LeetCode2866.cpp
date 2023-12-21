// LeetCode 2866 美丽塔II
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;
        vector<long long> presum(n), sufsum(n);
        stack<int> stk_pre, stk_suf;

        for (int i = 0; i < n; ++i) {
            while (!stk_pre.empty() &&
                   maxHeights[stk_pre.top()] > maxHeights[i]) {
                stk_pre.pop();
            }
            if (stk_pre.empty()) {
                presum[i] = 1LL * (i + 1) * maxHeights[i];
            } else {
                presum[i] = presum[stk_pre.top()] +
                            1LL * (i - stk_pre.top()) * maxHeights[i];
            }
            stk_pre.emplace(i);
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!stk_suf.empty() &&
                   maxHeights[stk_suf.top()] > maxHeights[i]) {
                stk_suf.pop();
            }
            if (stk_suf.empty()) {
                sufsum[i] = 1LL * (n - i) * maxHeights[i];
            } else {
                sufsum[i] = sufsum[stk_suf.top()] +
                            1LL * (stk_suf.top() - i) * maxHeights[i];
            }
            stk_suf.emplace(i);
            ans = max(ans, presum[i] + sufsum[i] - maxHeights[i]);
        }

        return ans;
    }
};