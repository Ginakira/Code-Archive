// LeetCode 2865 美丽塔 I

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
        for (int i = 0; i < n; ++i) {
            int pre = maxHeights[i];
            long long sum = pre;
            for (int j = i - 1; j >= 0; --j) {
                pre = min(pre, maxHeights[j]);
                sum += pre;
            }
            int suf = maxHeights[i];
            for (int j = i + 1; j < n; ++j) {
                suf = min(suf, maxHeights[j]);
                sum += suf;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

class Solution {
   public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;
        vector<long long> presum(n), sufsum(n);
        stack<int> stk1, stk2;

        for (int i = 0; i < n; ++i) {
            while (!stk1.empty() && maxHeights[stk1.top()] > maxHeights[i]) {
                stk1.pop();
            }
            if (stk1.empty()) {
                presum[i] = 1LL * (i + 1) * maxHeights[i];
            } else {
                presum[i] =
                    presum[stk1.top()] + 1LL * (i - stk1.top()) * maxHeights[i];
            }
            stk1.emplace(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!stk2.empty() && maxHeights[stk2.top()] > maxHeights[i]) {
                stk2.pop();
            }
            if (stk2.empty()) {
                sufsum[i] = 1LL * (n - i) * maxHeights[i];
            } else {
                sufsum[i] =
                    sufsum[stk2.top()] + 1LL * (stk2.top() - i) * maxHeights[i];
            }
            stk2.emplace(i);
            ans = max(ans, presum[i] + sufsum[i] - maxHeights[i]);
        }
        return ans;
    }
};