// LeetCode 907 子数组的最小值之和

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
    int sumSubarrayMins(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = std::stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + 1LL * (i - left[i]) * (right[i] - i) * arr[i]) % MOD;
        }
        return ans;
    }
};